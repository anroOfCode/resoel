#include <base.h>

#include <Hooks\HookProvider.h>
#include "ConsoleHooks.h"

/*
int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
    )
{
*/
int main() {
    auto consoleHooks = std::make_shared<ReSoel::Hooks::ConsoleHooks>();
    ReSoel::Hooks::SetTrampolineClient(consoleHooks);
    ReSoel::Hooks::SetDebugMode(true);
    ReSoel::Hooks::ApplyHooks();
    AllocConsole();
    std::cout << "This is a test!" << std::endl;
    return 0;
}