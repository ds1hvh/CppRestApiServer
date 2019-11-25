#pragma once

#include "TcpListener.h"

class WebServer : public TcpListener
{
public :
	WebServer(const char* ipAddress, int port) :
		TcpListener(ipAddress, port) { }

protected :

	// Handler for client connections
	void onClientConnected(int clientSocket);

	// Handler for client disconnections
	void onClientDisconnected(int clientSocket);

	// Handler for when a message is received from the client
	void onMessageReceived(int clientSocket, const char* msg, int length);
};