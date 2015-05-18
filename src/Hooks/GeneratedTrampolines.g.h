#pragma once

#include <base.h>
#include "HookBaseProvider.h"
#include <Utilities\DebugBuffer.h>

namespace ReSoel {
    namespace Hooks {
        class ITrampolineClient;

        class GeneratedTrampolines
            : public HookBaseProvider<GeneratedTrampolines>
        {
        public:
            GeneratedTrampolines();
            static void SetTrampolineClient(std::shared_ptr<ITrampolineClient> client);

        private:
            HookTable BuildHookTable() const override sealed;

            static BOOL WINAPI AllocConsoleHookStatic();
            BOOL AllocConsoleHook(void);

            std::shared_ptr<ITrampolineClient> m_client;
            ReSoel::Utilities::DebugBuffer m_debugBuffer;
            std::ostream m_debugOut;
        };
    }
}
