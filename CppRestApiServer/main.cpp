#include "WebServer.h"
#include<string>
#include<iostream>
#include<cstdlib>

extern int webServerTest(int argc, char *argv[]);
extern int gameTest();
#pragma comment (lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
	gameTest();
}