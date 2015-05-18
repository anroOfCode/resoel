#include "GeneratedTrampolines.g.h"

namespace ReSoel {
    namespace Hooks {
        void GeneratedTrampolines::SetTrampolineClient(std::shared_ptr<ITrampolineClient> client) {
            GetInstance().m_client = std::move(client);
        }

        GeneratedTrampolines::GeneratedTrampolines()
            : m_debugOut(&m_debugBuffer)
        {}
    }
}