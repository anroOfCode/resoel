#include "precomp.h"

//#include <easyhook.h>


class ConsoleScreenBuffer {
	int16_t m_x;
	int16_t m_y;

	int m_mode;
};

// A class that receives hooked method calls and stores state
// needed to efficiency send RPC messages to the server.
class ConsoleClientState {
public:

private:
	std::unordered_map<HANDLE, ConsoleScreenBuffer> m_buffers;
	uint16_t m_inputCodePage;
	uint16_t m_outputCodePage;
};

BOOL WINAPI AllocConsoleHook(void)
{
	std::cout << "Here we are!" << std::endl;
	return AllocConsole();
}

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	//HMODULE consoleModule = LoadLibraryW(L"api-ms-win-core-console-l1-1-0.dll");

	//HOOK_TRACE_INFO hook{};
	//ULONG ACLEntries[1] = { 0 };
	//void* addr = GetProcAddress(consoleModule, "AllocConsole");
	//auto result = LhInstallHook(
	//	GetProcAddress(consoleModule, "AllocConsole"),
	//	AllocConsoleHook,
	//	nullptr, &hook);
	//LhSetInclusiveACL(ACLEntries, 1, &hook);
	//AllocConsole();
	//std::cout << "Hello world" << std::endl;
	return 0;
}