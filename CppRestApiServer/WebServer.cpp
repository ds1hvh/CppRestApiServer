#include<string>
#include<fstream>
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
	std::ifstream f(".\\wwwroot\\index.html");
	std::string content = "";
	int code = 404;
	int size = 0;

	if (f.good())
	{
		std::string str((std::istreambuf_iterator<char>)f, std::istreambuf_iterator<char>());
		content = str;
		code = 200;
	}

	f.close();

	// Write the document back to the client
	std::ostringstream oss;
	oss << "HTTP/1.1 " << code << " OK\r\n";
	oss << "Cache-Control: no-cache, private\r\n";
	oss << "Content-Type: text/html\r\n";
	oss << "Content-Length: " << content.size() << "\r\n";
	oss << "\r\n";
	oss << content;
	
	std::string output = oss.str();
	size = output.size() + 1;

	sendToClient(clientSocket, output.c_str(), size);
}