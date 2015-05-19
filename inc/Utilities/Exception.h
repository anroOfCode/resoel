#pragma once

#include <base.h>

namespace ReSoel {
    namespace Utilities {

        // Processes are likely to terminate unexpectedly at any point during calls
        // against a wide API surface- the ideal use-case for C++ exception handling.
        //
        // You should assume that any of the methods on the Program class, or its contained
        // classes, have the ability to throw this exception when things like RPC pipes fail.
        class ProcessException 
            : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "An error has occurred establishing communication with the process";
            }
        };
    }
}