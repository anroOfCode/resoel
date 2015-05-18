#pragma once

#include <base.h>

namespace ReSoel {
    namespace Hooks {
        class ITrampolineClient
        {
        public:
            virtual void AllocConsolePost(BOOL) {}
            virtual void AllocConsolePre(void) {}
        };
    }
}