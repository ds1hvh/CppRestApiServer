
#include "Test.h"
#include "WebServer.h"
#include<string>
#include<iostream>
#include<cstdlib>

#define IPADDR "127.0.0.1"
#define PORT 8080

#pragma comment (lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
	webServerTest(IPADDR, PORT);
	return 0;
}