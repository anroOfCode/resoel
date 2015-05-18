#include <base.h>

namespace ReSoel {
    namespace Hooks {
        class ITrampolineClient;
        void ApplyHooks();
        void UnapplyHooks();
        void SetDebugMode(bool mode);
        void SetTrampolineClient(std::shared_ptr<ITrampolineClient> client);
    }
}