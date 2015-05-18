#pragma once

#include <base.h>
#include <easyhook.h>

namespace ReSoel {
    namespace Hooks {

        template<class T>
        class HookBaseProvider
        {
        public:
            // Because hooks are a global per-process thing we don't allow for
            // the creation of specific instances of the hook provider. Instead 
            // we give consumers of the hooks a static API to call against.
            static void ApplyHooks();
            static void UnapplyHooks();
            static void SetDebugMode(bool mode);

        protected:
            typedef std::vector<std::tuple<const char*, const char*, void*, HOOK_TRACE_INFO>> HookTable;

            // GetInstance is used with the CRTP idiom to provide a statically polymorphic
            // way to drop the implementation of the singleton into this base class while
            // still creating an instance of our outer-most derived class.
            static T& GetInstance() {
                static T instance;
                instance.EnsureInitialized();
                return instance;
            }

            HookBaseProvider() = default;
            HookBaseProvider(const HookBaseProvider&) = delete;
            HookBaseProvider& operator=(const HookBaseProvider&) = delete;

            virtual ~HookBaseProvider();
            bool GetDebugMode() const { return m_debugMode; }

        private:
            virtual HookTable BuildHookTable() const = 0;

            void Hook();
            void Unhook();
            void EnsureInitialized();

            HookTable m_table;
            bool m_initialized = false;
            bool m_hooked = false;
            bool m_debugMode = false;
        };

        template<class T>
        void HookBaseProvider<T>::ApplyHooks() {
            GetInstance().Hook();
        }

        template<class T>
        void HookBaseProvider<T>::UnapplyHooks() {
            GetInstance().Unhook();
        }

        template<class T>
        void HookBaseProvider<T>::SetDebugMode(bool mode) {
            GetInstance().m_debugMode = mode;
        }

        template<class T>
        HookBaseProvider<T>::~HookBaseProvider() {
            if (m_hooked) Unhook();
        }

        template<class T>
        void HookBaseProvider<T>::Hook() {
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

        template<class T>
        void HookBaseProvider<T>::Unhook() {
            assert(m_hooked);
            for (auto& entry : m_table) {
                ENSURE_NTSUCCESS(::LhUninstallHook(&std::get<3>(entry)));
            }
            ENSURE_NTSUCCESS(::LhWaitForPendingRemovals());
            m_hooked = false;
        }

        template<class T>
        void HookBaseProvider<T>::EnsureInitialized() {
            if (!m_initialized) m_table = BuildHookTable();
        }
    }
}
