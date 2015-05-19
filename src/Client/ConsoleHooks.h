#pragma once

#include <base.h>
#include <Hooks\ITrampolineClient.g.h>

namespace ReSoel {
    namespace Hooks {

        class ConsoleHooks
            : public ITrampolineClient
        {
        public:
            void AllocConsolePre() override;
            void AllocConsolePost(BOOL result) override;
        };
    }
}
