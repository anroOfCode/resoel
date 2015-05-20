#pragma once

#include <base.h>
#include <Utilities\Exception.h>

namespace ReSoel {
    namespace Server {

        // Represents a child process of the ReSoel server application, with
        // its input and output console handles hooked. 
        class Program
        {
        public:
            Program(std::string workingPath, std::string programName, std::string arguments);
            Program(SharedHandle process);
            Program(const Program&) = delete;
            ~Program();

        private:
            SharedHandle StartProcess(const std::string& workingPath, const std::string& programName, const std::string& arguments) const;
            void AttachConsoleHooks(bool suspended);
            bool Is64BitProcess() const;
            SharedHandle m_process;

            // Debug / informational purposes.
            std::string m_workingPath;
            std::string m_programName;
            std::string m_arguments;
        };

    }
}