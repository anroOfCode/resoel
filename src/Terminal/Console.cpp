#include <base.h>
#include <Terminal\Console.h>

namespace ReSoel {

    std::mutex ConsoleSingleton::s_mutex;
    std::shared_ptr<Console> ConsoleSingleton::s_instance;

    Console& ConsoleSingleton::GetInstance()
    {
        std::lock_guard<std::mutex> lock(s_mutex);
        if (!s_instance) s_instance = std::make_shared<Console>();
        return *s_instance.get();
    }

    bool ConsoleSingleton::Initialize() {
        std::lock_guard<std::mutex> lock(s_mutex);
        if (s_instance) return false;
        s_instance = std::make_shared<Console>();
        return true;
    }

    bool ConsoleSingleton::Deinitialize() {
        std::lock_guard<std::mutex> lock(s_mutex);
        if (!s_instance) return false;
        s_instance.reset();
        return true;
    }

    bool ConsoleSingleton::IsInitialized() {
        return s_instance != nullptr;
    }

    namespace Win32FrontEnd {
        BOOL WINAPI AllocConsole(void) {
            if (ConsoleSingleton::Initialize()) return TRUE;
            SetLastError(ERROR_ACCESS_DENIED);
            return FALSE;
        }

        BOOL WINAPI FreeConsole(void) {
            if (ConsoleSingleton::Deinitialize()) return TRUE;
            SetLastError(ERROR_INVALID_PARAMETER);
            return FALSE;
        }

        BOOL WINAPI AttachConsole(DWORD processId) {
            if (processId == ATTACH_PARENT_PROCESS) {
                return AllocConsole();
            }
            else {
                SetLastError(ERROR_GEN_FAILURE);
                return FALSE;
            }
        }
    }
}
