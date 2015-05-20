#include "Program.h"
#include <Utilities\CharacterConverter.h>

namespace ReSoel {
    namespace Server {

        Program::Program(const std::string& workingPath, const std::string& programName, const std::string& arguments)
            : Program(StartProcess(workingPath, programName, arguments))
        {}

        Program::Program(SharedHandle process) 
            : m_process(std::move(process))
        {
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
            if (!CreateProcessW(
                &wProgramName[0],
                &wArguments[0],
                nullptr, nullptr, FALSE, CREATE_NEW_CONSOLE, nullptr, 
                wWorkingPath.c_str()[0] == 0 ? nullptr : &wWorkingPath[0],
                &startInfo, &processInfo)) {
                throw ReSoel::Utilities::ProcessException();
            }
            return std::shared_ptr<void>(processInfo.hProcess, ::CloseHandle);
        }

        void Program::AttachConsoleHooks()
        {

        }
    }
}