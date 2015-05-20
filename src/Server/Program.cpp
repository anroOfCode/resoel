#include "Program.h"
#include <Utilities\CharacterConverter.h>
#include <easyhook.h>
#include <DbgHelp.h>

namespace ReSoel {
    namespace Server {

        Program::Program(std::string workingPath, std::string programName, std::string arguments)
            : Program(StartProcess(workingPath, programName, arguments))
        {
            m_workingPath = std::move(workingPath);
            m_programName = std::move(programName);
            m_arguments = std::move(arguments);
            AttachConsoleHooks(true);
        }

        Program::Program(SharedHandle process) 
            : m_process(std::move(process))
        {
            AttachConsoleHooks(false);
        }

        Program::~Program()
        {
            if (m_process) TerminateProcess(m_process.get(), 0);
        }

        SharedHandle Program::StartProcess(const std::string& workingPath, 
            const std::string& programName, const std::string& arguments) const
        {
            auto wProgramName = ReSoel::Utilities::Utf8ToWindowsString(programName);
            auto wArguments = ReSoel::Utilities::Utf8ToWindowsString(arguments);
            auto wWorkingPath = ReSoel::Utilities::Utf8ToWindowsString(workingPath);
            STARTUPINFO startInfo{};
            startInfo.cb = sizeof(startInfo);
            PROCESS_INFORMATION processInfo{};

            // We're making kind of an evil assumption about std::string having a
            // NULL-terminated string internally as CreateProcessW is expecting it and
            // can theoretically modify the wchar_t strings passed to it, which is why
            // we didn't use c_str(). Either way we have to crack open the abstraction
            // and admit to ourselves that we really are null-terminated at the end of
            // the day. 
            // FUTURE: It would be nice to rip this thing into a job object to ensure 
            // that we terminate all children processes as well.
            if (!CreateProcessW(
                &wProgramName[0],
                &wArguments[0],
                nullptr, nullptr, FALSE, CREATE_NEW_CONSOLE, nullptr,
                wWorkingPath.c_str()[0] == 0 ? nullptr : &wWorkingPath[0],
                &startInfo, &processInfo)) {
                throw ReSoel::Utilities::ProcessException("Call to CreateProcessW failed.");
            }
            return std::shared_ptr<void>(processInfo.hProcess, ::CloseHandle);
        }

        bool Program::Is64BitProcess() const
        {
            BOOL is32Bit = FALSE;
            if (!IsWow64Process(m_process.get(), &is32Bit)) {
                throw ReSoel::Utilities::ProcessException("Call to IsWow64Process failed.");
            }
            return !is32Bit;
        }

        void Program::AttachConsoleHooks(bool suspended)
        {
            void* loadLibraryAddress = GetLoadLibraryAddress();
            const char* moduleName = Is64BitProcess() ? "ReSoel.Client64.dll" : "ReSoel.Client32.dll";
            
            void* remoteAlloc = VirtualAllocEx(m_process.get(), nullptr, strlen(moduleName), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
            if (!remoteAlloc) 
                throw ReSoel::Utilities::ProcessException("Failed to allocate RemoteInjection buffer.");

            if (!WriteProcessMemory(m_process.get(), remoteAlloc, moduleName, strlen(moduleName), nullptr))
                throw ReSoel::Utilities::ProcessException("Failed to write to RemoteInjection buffer.");

            // FUTURE: Synchronize on this remote thread handle.
            HANDLE remoteThread = CreateRemoteThread(
                m_process.get(), nullptr, 0, (LPTHREAD_START_ROUTINE)loadLibraryAddress, remoteAlloc, 0, nullptr);
        }

        void* Program::GetLoadLibraryAddress() const
        {
            SymSetOptions(SymGetOptions() | SYMOPT_INCLUDE_32BIT_MODULES);
            // FUTURE: Synchronize on remote process DLL load, perhaps using initial debug break?
            if (!SymInitialize(m_process.get(), nullptr, true))
                throw ReSoel::Utilities::ProcessException("Failed to load debug information.");

            ULONG64 buffer[(sizeof(SYMBOL_INFO) +
                MAX_SYM_NAME * sizeof(TCHAR) +
                sizeof(ULONG64) - 1) /
                sizeof(ULONG64)];
            PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)buffer;
            pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
            pSymbol->MaxNameLen = MAX_SYM_NAME;

            if (!SymFromName(m_process.get(), "LoadLibraryA", pSymbol))
                throw ReSoel::Utilities::ProcessException("Failed to load debug information.");

            // FUTURE: RAII wrapper here to properly cleanup DbgHelp.
            SymCleanup(m_process.get());
            return reinterpret_cast<void*>(pSymbol->Address);
        }

    }
}