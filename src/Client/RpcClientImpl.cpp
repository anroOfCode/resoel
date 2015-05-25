#include "RpcClientImpl.h"

#include <MidlAlloc.h>
#include <ResoelRpc_c.c>

namespace ReSoel {
    namespace Client {
        namespace Rpc {
            void StartRpcClient()
            {
                unsigned char* rpcBinding = nullptr;
                ENSURE_SUCCESS(RpcStringBindingComposeA(nullptr,
                    (unsigned char*)"ncacn_np",
                    nullptr,
                    (unsigned char*)"\\pipe\\resoel",
                    nullptr, &rpcBinding));
                ENSURE_SUCCESS(RpcBindingFromStringBindingA(rpcBinding, &resoel_IfHandle));
            }
        }
    }
}