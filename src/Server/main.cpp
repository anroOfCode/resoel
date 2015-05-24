#include <base.h>

#include "Program.h"

int main() 
{
    std::cout << "ReSoel Console Server ALPHA" << std::endl;
    std::cout << "May god have mercy on all those that use this unfinished software" << std::endl;
	
	ReSoel::Server::Program prog(
		ReSoel::Server::CreateProcessInjector("C:\\Users", 
			"C:\\windows\\syswow64\\notepad.exe", "").GetProcessHandle());

    return 0;
}