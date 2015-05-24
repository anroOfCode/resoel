#include "Program.h"
#include <Utilities\CharacterConverter.h>
#include <easyhook.h>
#include <DbgHelp.h>
#include <Shlwapi.h>

#pragma comment(lib, "shlwapi.lib")

namespace ReSoel {
    namespace Server {
		
		static const int s_debugWaitTimeoutMs = 3000;

		namespace ProcessHelpers {
			bool Is64BitProcess(HANDLE process) 
			{
				BOOL is32Bit = FALSE;
				if (!IsWow64Process(process, &is32Bit)) {
					throw ReSoel::Utilities::ProcessException("Call to IsWow64Process failed.");
				}
				return !is32Bit;
			}

			std::string GetFullPathOfResoelModule(const char* moduleName)
			{
				std::string ret(MAX_PATH, 0);
				DWORD length = GetModuleFileNameA(nullptr, &ret[0], static_cast<DWORD>(ret.size()));
				PathRemoveFileSpecA(&ret[0]);
				PathAppendA(&ret[0], moduleName);
				return ret;
			}

			void* GetLoadLibraryAddress(HANDLE process, HANDLE kernel32FileHandle, DWORD64 baseAddress, DWORD moduleLength)
			{
				SymSetOptions(SymGetOptions() | SYMOPT_INCLUDE_32BIT_MODULES);
				if (!SymInitialize(process, nullptr, true))
					throw ReSoel::Utilities::ProcessException("Failed to load debug information.");

				if (!SymLoadModuleEx(process, kernel32FileHandle, nullptr, nullptr, baseAddress, moduleLength, nullptr, 0))
					throw ReSoel::Utilities::ProcessException("Failed to load kernel32 debug export information.");

				ULONG64 buffer[(sizeof(SYMBOL_INFO)+
					MAX_SYM_NAME * sizeof(TCHAR)+
					sizeof(ULONG64)-1) /
					sizeof(ULONG64)];
				PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)buffer;
				pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
				pSymbol->MaxNameLen = MAX_SYM_NAME;

				if (!SymFromName(process, "LoadLibraryA", pSymbol))
					throw ReSoel::Utilities::ProcessException("Failed to load debug information.");

				// FUTURE: RAII wrapper here to properly cleanup DbgHelp?
				SymCleanup(process);
				return reinterpret_cast<void*>(pSymbol->Address);
			}

			void AttachConsoleHooks(HANDLE process, void* loadLibraryAddress, bool suspended)
			{
				auto moduleName = GetFullPathOfResoelModule(Is64BitProcess(process) ? 
					"ReSoel.Client.dll" : "ReSoel.Client32.dll");

				// We're not going to worry about this block of memory- you know what they
				// say- you can't take it with you!
				void* remoteAlloc = VirtualAllocEx(process, nullptr, strlen(moduleName.c_str()), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
				if (!remoteAlloc)
					throw ReSoel::Utilities::ProcessException("Failed to allocate RemoteInjection buffer.");

				if (!WriteProcessMemory(process, remoteAlloc, moduleName.c_str(), strlen(moduleName.c_str()), nullptr))
					throw ReSoel::Utilities::ProcessException("Failed to write to RemoteInjection buffer.");

				HANDLE remoteThread = CreateRemoteThread(
					process, nullptr, 0, (LPTHREAD_START_ROUTINE)loadLibraryAddress, remoteAlloc, 0, nullptr);
			}
		}

		AttachProcessInjector::AttachProcessInjector(SharedHandle process)
			: m_process(std::move(process))
		{}

		SharedHandle AttachProcessInjector::GetProcessHandle()
		{
			return std::move(m_process);
		}

		CreateProcessInjector::CreateProcessInjector(std::string workingPath, 
			std::string programName, std::string arguments)
		{
			m_process = StartProcess(workingPath, programName, arguments);

			// Wait for the initial breakpoint to be hit and suspend the calling
			// thread.
			auto initialInfo = WaitForLoadLibraryModuleLoad();
			auto remoteMainThread = std::shared_ptr<void>(
				OpenThread(THREAD_ALL_ACCESS, FALSE, initialInfo.ThreadId), CloseHandle);
			if (!remoteMainThread)
				throw ReSoel::Utilities::ProcessException("Failed to open remote process thread.");
			if (SuspendThread(remoteMainThread.get()) == -1)
				throw ReSoel::Utilities::ProcessException("Failed to suspend remote process thread.");
			// And now detach, we've suspended the thread and have full control over the target.
			// This will drain the debug event queue.
			DebugActiveProcessStop(initialInfo.ProcessId);
			ProcessHelpers::AttachConsoleHooks(m_process.get(), initialInfo.LoadLibraryAPtr, true);

			// And now we're off to the horse races!
			if (ResumeThread(remoteMainThread.get()) == -1)
				throw ReSoel::Utilities::ProcessException("Failed to resume remote process thread.");
		}

		SharedHandle CreateProcessInjector::GetProcessHandle()
		{
			return std::move(m_process);
		}

        SharedHandle CreateProcessInjector::StartProcess(const std::string& workingPath, 
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
			//
            // FUTURE: It would be nice to rip this thing into a job object to ensure 
            // that we terminate all children processes as well.
			// 
			// We create the process detached so that there's no opppertunity for
			// it to attach to our console or have knowledge of its parent process.
			// We also create the process in debug mode, so that we can wait for the
			// initial process creation breakpoint to load up our hook DLL.
            if (!CreateProcessW(
                &wProgramName[0],
                &wArguments[0],
				nullptr, nullptr, FALSE, DETACHED_PROCESS | DEBUG_ONLY_THIS_PROCESS, nullptr,
                wWorkingPath.c_str()[0] == 0 ? nullptr : &wWorkingPath[0],
                &startInfo, &processInfo)) {
                throw ReSoel::Utilities::ProcessException("Call to CreateProcessW failed.");
            }
            return std::shared_ptr<void>(processInfo.hProcess, ::CloseHandle);
        }



		CreateProcessInjector::InitialDebugInfo CreateProcessInjector::WaitForLoadLibraryModuleLoad() const
		{
			const wchar_t* moduleName = ProcessHelpers::Is64BitProcess(m_process.get()) ?
				L"system32\\kernel32.dll" : L"syswow64\\kernel32.dll";

			while (true)
			{
				DEBUG_EVENT dEvent{};
				if (!WaitForDebugEvent(&dEvent, s_debugWaitTimeoutMs))
					throw ReSoel::Utilities::ProcessException("Debug wait timeout failed.");

				if (dEvent.dwDebugEventCode == LOAD_DLL_DEBUG_EVENT)
				{
					DWORD nSize = sizeof(FILE_NAME_INFO) + MAX_PATH * sizeof(wchar_t);
					auto fileInfo = std::unique_ptr<FILE_NAME_INFO>(reinterpret_cast<FILE_NAME_INFO*>(malloc(nSize)));
					if (!GetFileInformationByHandleEx(dEvent.u.LoadDll.hFile, FileNameInfo, fileInfo.get(), nSize))
						throw ReSoel::Utilities::ProcessException("Getting DLL load info failed.");

					if ((fileInfo->FileNameLength / 2) < wcslen(moduleName)) continue;
					if (_wcsnicmp(fileInfo->FileName + (fileInfo->FileNameLength / 2) - wcslen(moduleName), moduleName, wcslen(moduleName)) == 0)
					{
						InitialDebugInfo info;
						info.LoadLibraryAPtr = ProcessHelpers::GetLoadLibraryAddress(m_process.get(),
							dEvent.u.LoadDll.hFile, reinterpret_cast<DWORD64>(dEvent.u.LoadDll.lpBaseOfDll),
							dEvent.u.LoadDll.nDebugInfoSize);
						info.ProcessId = dEvent.dwProcessId;
						info.ThreadId = dEvent.dwThreadId;
						return info;
					}
				}

				ContinueDebugEvent(dEvent.dwProcessId, dEvent.dwThreadId, DBG_CONTINUE);
			}
		}

        Program::Program(SharedHandle process) 
            : m_process(std::move(process))
        {}

        Program::~Program()
        {
            if (m_process) TerminateProcess(m_process.get(), 0);
        }

    }
}