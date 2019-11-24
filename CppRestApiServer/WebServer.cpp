#include<string>
#include<iostream>
#include<sstream>
#include "WebServer.h"

// Handler for when a message is received from the client
void WebServer::onClientConnected(int clientSocket)
{

}

void WebServer::onClientDisconnected(int clientSocket)
{

}

void WebServer::onMessageReceived(int clientSocket, const char* msg, int length)
{

	// Get /index.html HTTP/1.1

	// Parse out the document requested
	// Open the document in the local file system
	// Write the document back to the client
	std::ostringstream oss;
	oss << "HTTP/1.1 200 OK\r\n";
	oss << "Cache-Control: no-cache, private\r\n";
	oss << "Content-Type: text/plain\r\n";
	oss << "Content-Length: 5\r\n";
	oss << "\r\n";
	oss << "hello";
	
	std::string output = oss.str();
	int size = output.size() + 1;

	sendToClient(clientSocket, output.c_str(), size);
}