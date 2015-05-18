#include <Hooks\HookProvider.h>
#include "GeneratedTrampolines.g.h"

namespace ReSoel {
    namespace Hooks {
        void ApplyHooks() {
            GeneratedTrampolines::ApplyHooks();
        }

        void UnapplyHooks() {
            GeneratedTrampolines::UnapplyHooks();
        }

        void SetDebugMode(bool mode) {
            GeneratedTrampolines::SetDebugMode(mode);
        }

        void SetTrampolineClient(std::shared_ptr<ITrampolineClient> client) {
            GeneratedTrampolines::SetTrampolineClient(std::move(client));
        }
    }
}