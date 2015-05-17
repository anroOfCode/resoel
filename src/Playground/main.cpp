#include <base.h>
#include <easyhook.h>

namespace ReSoel {
    namespace Win32Hooks{
        template<class T>
        class HookInfrastructure
        {
        public:
            static void ApplyHooks() {
                GetInstance().Hook();
            }

            static void UnapplyHooks() {
                GetInstance().Unhook();
            }

            static void SetDebugMode(bool mode) {
                GetInstance().m_debugMode = mode;
            }

        protected:
            typedef std::vector<std::tuple<const char*, const char*, void*, HOOK_TRACE_INFO>> HookTable;

            static T& GetInstance() {
                static T instance;
                instance.EnsureInitialized();
                return instance;
            }

            HookInfrastructure() = default;
            HookInfrastructure(const HookInfrastructure&) = delete;
            HookInfrastructure& operator=(const HookInfrastructure&) = delete;

            virtual ~HookInfrastructure() {
                if (m_hooked) {
                    Unhook();
                }
            }

            bool GetDebugMode() const { return m_debugMode; }

        private:
            void Hook() {
                assert(!m_hooked);
                for (auto& entry : m_table) {
                    // We don't really worry about DLL handles leaking- we want to keep the DLL loaded into memory for the duration of the
                    // process as we don't want the proc address to change on us and it's not like we're going to leak after the application
                    // shuts down.
                    HMODULE module = LoadLibraryA(std::get<0>(entry));

                    auto procAddress = GetProcAddress(module, std::get<1>(entry));
                    ENSURE_NTSUCCESS(::LhInstallHook(procAddress, std::get<2>(entry), nullptr, &std::get<3>(entry)));
                    ULONG ACLEntries[1] = { 0 };
                    ENSURE_NTSUCCESS(::LhSetInclusiveACL(ACLEntries, 1, &std::get<3>(entry)));
                }
                m_hooked = true;
            }

            void Unhook() {
                assert(m_hooked);
                for (auto& entry : m_table) {
                    ENSURE_NTSUCCESS(::LhUninstallHook(&std::get<3>(entry)));
                }
                ENSURE_NTSUCCESS(::LhWaitForPendingRemovals());
                m_hooked = false;
            }

            void EnsureInitialized() {
                if (!m_initialized) m_table = BuildHookTable();
            }

            HookTable m_table;
            bool m_initialized = false;
            bool m_hooked = false;
            virtual HookTable BuildHookTable() const = 0;
            bool m_debugMode = false;
        };

        class ConsoleHooks;
        class GeneratedHooks 
            : public HookInfrastructure<ConsoleHooks>
        {
            friend BOOL WINAPI AllocConsoleHookStatic();

        protected:
            virtual void AllocConsolePost(BOOL) {}
            virtual void AllocConsolePre(void) {}

        private:
            static BOOL WINAPI AllocConsoleHookStatic();

            BOOL AllocConsoleHook(void)
            {
                AllocConsolePre();
                auto result = ::AllocConsole();
                AllocConsolePost(result);
                return result;
            }

            HookTable BuildHookTable() const override sealed {
                static const char* kernel32Dll = "kernel32.dll";
                return HookTable{
                    std::make_tuple(kernel32Dll, "AllocConsole", (void*)AllocConsoleHookStatic, HOOK_TRACE_INFO{}),
                };
            }
        };

        class ConsoleHooks 
            : public GeneratedHooks
        {
        private:
            void AllocConsolePre() override
            {
                OutputDebugStringW(L"PreCall hit.\n");
            }

            void AllocConsolePost(BOOL result) override
            {
                OutputDebugStringW(L"PostCall hit.\n");
            }
        };

        BOOL WINAPI GeneratedHooks::AllocConsoleHookStatic() {
            return GetInstance().AllocConsoleHook();
        }
    }
}


int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
    )
{
    ReSoel::Win32Hooks::ConsoleHooks::ApplyHooks();
    AllocConsole();
    return 0;
}