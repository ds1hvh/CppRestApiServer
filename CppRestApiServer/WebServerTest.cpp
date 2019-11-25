#include "Test.h"
#include "WebServer.h"
#include<iostream>

int webServerTest(const char* ipAddr, int port) {
	
	WebServer web_server(ipAddr, port);
	if (web_server.init() != 0)
		return -1;

	web_server.run();
	return 0;
}