#include <base.h>

#include "RpcClientImpl.h"
#include <ResoelRpc.h>

DWORD WINAPI RpcFun(LPVOID)
{
    ReSoel::Client::Rpc::StartRpcClient();
    Announce();
    return 0;
}

BOOL WINAPI DllMain(
    _In_ HINSTANCE hinstDLL,
    _In_ DWORD     fdwReason,
    _In_ LPVOID    lpvReserved
    )
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        CreateThread(nullptr, 0, RpcFun, nullptr, 0, nullptr);
    }
    return TRUE;
}