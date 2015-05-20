#include "Program.h"
#include <Utilities\CharacterConverter.h>
#include <easyhook.h>

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
                nullptr, nullptr, FALSE, CREATE_NEW_CONSOLE | CREATE_SUSPENDED, nullptr,
                wWorkingPath.c_str()[0] == 0 ? nullptr : &wWorkingPath[0],
                &startInfo, &processInfo)) {
                throw ReSoel::Utilities::ProcessException("Call to CreateProcessW failed.");
            }
            return std::shared_ptr<void>(processInfo.hProcess, ::CloseHandle);
        }

        bool Program::Is64BitProcess() const
        {
            BOOL is64Bit = FALSE;
            if (!IsWow64Process(m_process.get(), &is64Bit)) {
                throw ReSoel::Utilities::ProcessException("Call to IsWow64Process failed.");
            }
            return !!is64Bit;
        }

        void Program::AttachConsoleHooks(bool suspended)
        {
            // Figure out if we're 64-bit or a 32-bit processs and then generate
            // the right code block in memory...

            // - Use DbgHelp module information to locate the address of LoadLibraryA
            // - Pass it as the entry point to CreateRemoteThread
            // - Alloc a string to the 32-bit or 64-bit hook client in the remote DLL
            // - Let it all rip.

            //auto remoteThread = CreateRemoteThread(
            //    m_process.get(), nullptr, 0, START, PARAM, 0, nullptr);
        }
    }
}