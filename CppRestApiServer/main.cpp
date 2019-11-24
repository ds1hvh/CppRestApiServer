#include "WebServer.h"
#define IPADDR "0.0.0.0"
#define PORT 8080

#pragma comment (lib, "ws2_32.lib")

int main() 
{
	WebServer webServer(IPADDR, PORT);
	if (webServer.init() != 0) {
		return -1;
	}
	webServer.run();
	return 0;
}