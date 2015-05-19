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
            Program(const std::string& workingPath, const std::string& programName, const std::string& arguments);
            Program(SharedHandle process);
            Program(const Program&) = delete;

        private:
            SharedHandle StartProcess(const std::string& workingPath, const std::string& programName, const std::string& arguments) const;
            void AttachConsoleHooks();
            SharedHandle m_process;
        };

    }
}