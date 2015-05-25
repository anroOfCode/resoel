#include "RpcImpl.h"

#include <MidlAlloc.h>
#include <ResoelRpc_s.c>

void Announce()
{
    std::cout << "lol" << std::endl;
}

namespace ReSoel {
    namespace Server {
        namespace Rpc {
            void StartRpcServer()
            {
                ENSURE_SUCCESS(RpcServerUseProtseqEpA(
                    (unsigned char*)"ncacn_np",
                    RPC_C_LISTEN_MAX_CALLS_DEFAULT,
                    (unsigned char*)"\\pipe\\resoel", nullptr));
                ENSURE_SUCCESS(RpcServerRegisterIf(
                    ResoelRpc_v1_0_s_ifspec, nullptr, nullptr));
                ENSURE_SUCCESS(RpcServerListen(1, RPC_C_LISTEN_MAX_CALLS_DEFAULT, TRUE));
            }

            void StopRpcServer()
            {
                ENSURE_SUCCESS(RpcMgmtStopServerListening(nullptr));
                ENSURE_SUCCESS(RpcServerUnregisterIf(nullptr, nullptr, FALSE));
            }
        }
    }
}