#include "GeneratedTrampolines.g.h"
#include <Hooks\ITrampolineClient.g.h>
#include <easyhook.h>

namespace ReSoel {
    namespace Hooks {
        BOOL GeneratedTrampolines::AllocConsoleHook(void) {
            if (GetDebugMode()) m_debugOut << "[AllocConsole]::BeginHook" << std::endl;
            if (m_client) m_client->AllocConsolePre();
            auto result = ::AllocConsole();
            if (m_client) m_client->AllocConsolePost(result);
            return result;
        }

        BOOL WINAPI GeneratedTrampolines::AllocConsoleHookStatic() {
            return GetInstance().AllocConsoleHook();
        }

        GeneratedTrampolines::HookTable GeneratedTrampolines::BuildHookTable() const {
            static const char* kernel32Dll = "kernel32.dll";
            return HookTable{
                std::make_tuple(kernel32Dll, "AllocConsole", (void*)AllocConsoleHookStatic, HOOK_TRACE_INFO{}),
            };
        }

        void GeneratedTrampolines::SetTrampolineClient(std::shared_ptr<ITrampolineClient> client) {
            GetInstance().m_client = std::move(client);
        }

        GeneratedTrampolines::GeneratedTrampolines() 
            : m_debugOut(&m_debugBuffer)
        {}
    }
}