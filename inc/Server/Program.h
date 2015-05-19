#pragma once

#include <base.h>

namespace ReSoel {
    namespace Server {

        // Represents a child process of the ReSoel server application, with
        // its input and output console handles hooked. 
        class Program
        {
        public:
            Program(std::string workingPath, std::string programName, std::string arguments);
            Program(const Program&) = delete;
        };

    }
}