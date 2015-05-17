#pragma once

namespace ReSoel {
    class Console {
    public:
        Console() = default;
        void operator=(Console const&) = delete;
        Console(Console const&) = delete;
    private:

    };

    class ConsoleSingleton {
    public:
        ConsoleSingleton() = delete;

        static Console& GetInstance();
        static bool Initialize();
        static bool Deinitialize();
        static bool IsInitialized();
    private:
        static std::mutex s_mutex;
        static std::shared_ptr<Console> s_instance;        
    };

    // Contains the direct Win32 API methods that operate on a singleton instance of
    // ReSoel::Console.
    namespace Win32FrontEnd {
        BOOL WINAPI AllocConsole(void);
        BOOL WINAPI FreeConsole(void);

        // We only support the current process for attaching to a console.
        // All other processes will return a general failure error.
        BOOL WINAPI AttachConsole(DWORD processId);
    }
}


