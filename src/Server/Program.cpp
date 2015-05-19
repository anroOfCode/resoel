#include "Program.h"

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

            std::wstring workingWidePath();
            return SharedHandle();
        }

        void Program::AttachConsoleHooks()
        {

        }
    }
}