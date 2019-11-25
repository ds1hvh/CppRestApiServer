#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include "WebServer.h"


// Handler for when a message is received from the client
void WebServer::onClientConnected(int clientSocket)
{
	std::cout << "[CON]client" << clientSocket << " connected!" << std::endl;
}

void WebServer::onClientDisconnected(int clientSocket)
{
		std::cout << "[DIS]client" << clientSocket << " disconnected!" << std::endl;
}

void WebServer::onMessageReceived(int clientSocket, const char* msg, int length)
{
	// Parse out the document requested
	std::istringstream iss(msg);
	std::vector<std::string> parsed((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

	std::string content = "";
	std::string uri = "/index.html";
	int code = 404;
	int size = 0;

	if (parsed.size() >= 3 && parsed[0] == "GET") // HTTP Methods len >= 3
	{
		uri = parsed[1];

		// default page
		if (uri == "/")
		{
			uri = "/index.html";
			
			// Open the document in the local file system
			std::ifstream f(".\\wwwroot" + uri);

			if (f.good())
			{
				std::string str((std::istreambuf_iterator<char>)f, std::istreambuf_iterator<char>());
				content = str;
				code = 200;
			}

			f.close();
		}
		else if (uri == "/game")
		{
			
			
		}
	}
	
	

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