#include <base.h>

#include "Program.h"
#include "RpcImpl.h"

int main() 
{
    std::cout << "ReSoel Console Server ALPHA" << std::endl;
    std::cout << "May god have mercy on all those that use this unfinished software" << std::endl;

    ReSoel::Server::Rpc::StartRpcServer();
    ReSoel::Server::Program prog(
        ReSoel::Server::CreateProcessInjector("C:\\Users", 
            "C:\\windows\\system32\\notepad.exe", "").GetProcessHandle());
    Sleep(10000);
    return 0;
}