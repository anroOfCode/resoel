
#include "ConsoleHooks.h"

namespace ReSoel {
    namespace Hooks {
        void ConsoleHooks::AllocConsolePre() 
        {
            OutputDebugStringW(L"PreCall hit.\n");
        }

        void ConsoleHooks::AllocConsolePost(BOOL result)
        {
            OutputDebugStringW(L"PostCall hit.\n");
        }
    }
}