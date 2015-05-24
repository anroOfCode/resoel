#pragma once

#include <base.h>
#include <Utilities\Exception.h>

namespace ReSoel {
    namespace Server {
		namespace ProcessHelpers {
            void AttachConsoleHooks(HANDLE process, void* loadLibraryAddress, bool suspended);
            bool Is64BitProcess(HANDLE process);
			void* GetLoadLibraryAddress(HANDLE process);
			void* GetLoadLibraryAddress(HANDLE process, HANDLE kernel32FileHandle, DWORD64 baseAddress, DWORD moduleLength);
			std::string GetFullPathOfResoelModule(const char* moduleName);
		}

		class AttachProcessInjector
		{
		public:
			AttachProcessInjector(DWORD pid);
			AttachProcessInjector(SharedHandle process);
			AttachProcessInjector(const AttachProcessInjector&) = delete;
			SharedHandle GetProcessHandle();

		private:
			SharedHandle m_process;
		};

		class CreateProcessInjector
		{
		public:
			CreateProcessInjector(std::string workingPath, std::string programName, std::string arguments);
			CreateProcessInjector(const CreateProcessInjector&) = delete;
			SharedHandle GetProcessHandle();

		private:
            SharedHandle StartProcess(const std::string& workingPath, const std::string& programName, const std::string& arguments) const;
			struct InitialDebugInfo {
				DWORD ProcessId;
				DWORD ThreadId;
				void* LoadLibraryAPtr;
			};
			InitialDebugInfo WaitForLoadLibraryModuleLoad() const;
            SharedHandle m_process;
		};

        // Represents a child process of the ReSoel server application, with
        // its input and output console handles hooked. 
        class Program
        {
        public:
            Program(SharedHandle process);
            Program(const Program&) = delete;
            ~Program();

        private:
			SharedHandle m_process;
        };

    }
}