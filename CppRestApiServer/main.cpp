#include<iostream>
#include<WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

int main() 
{
	// Initialize winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0) 
	{
		cerr << "Can't Initialize winsock! Quitting" << endl;
		return 1;
	}

	// Create a socket

	// Bind the socket to an ip address and port

	// Tell Winsock the socket is for listening

	// Wait for a connection

	// Close listening socket

	// While loop : accept and echo message back to client

	// Close the sock

	// Shutdown winsock
	
	return 0;
}