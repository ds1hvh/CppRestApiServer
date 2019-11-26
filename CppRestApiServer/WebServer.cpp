#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "WebServer.h"
#include "game/Board.h"
#include "JsonOBJ.h"

// Handler for when a message is received from the client
void WebServer::onClientConnected(int clientSocket)
{
	std::cout << "[CON]Client" << clientSocket << " connected!" << std::endl;
}

void WebServer::onClientDisconnected(int clientSocket)
{
		std::cout << "[DIS]Client" << clientSocket << " disconnected!" << std::endl;
}

void WebServer::onMessageReceived(int clientSocket, const char* msg, int length)
{
	// Parse out the document requested
	std::istringstream iss(msg);
	std::vector<std::string> parsed((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

	std::cout << "[REQ]Client" << clientSocket << " ";
	for (int i = 0; i < 3; i++) {
		std::cout << parsed.at(i) << " ";
	}
	std::cout << std::endl;

	std::string uri = "/index.html";
	std::string content_type = "text/html";
	std::string content = "";
	std::string parameter = "";
	int code = 404;
	int size = 0;
	Board board(0);
	rapidjson::Document document;

	if (parsed.size() >= 3) // HTTP request len >= 3
	{
		uri = parsed[1];
		if (parsed[0] == "GET") 
		{
			if (uri == "/game")
			{
				JsonOBJ json;
				json.add("data", board);
				content = json.getStr();
				std::cout << content;
			}
			else
			{
				// default page
				if (uri == "/")
				{
					uri = "/index.html";
				}

				// Open the document in the local file system
				std::ifstream f(".\\wwwroot" + uri);

				if (f.good())
				{
					std::string str((std::istreambuf_iterator<char>)f, std::istreambuf_iterator<char>());
					content = str;
				}

				f.close();
			}
			
			code = 200;
		}
		else if(parsed[0] == "POST")
		{
			if (uri == "/new")
			{
				parameter = parsed.back();
				document.Parse(parameter.c_str());
				std::cout << "-----------------------------" << std::endl;
				std::cout << "size: " << document["size"].GetInt() << std::endl;
				std::cout << "-----------------------------" << std::endl;
				board.init(document["size"].GetInt());
				
				content = "";
				code = 200;
			}
		}
		
	}
	
	// Write the document back to the client
	std::ostringstream oss;
	oss << "HTTP/1.1 " << code << " OK\r\n";
	oss << "Cache-Control: no-cache, private\r\n";
	oss << "Content-Type: "<<content_type<<"\r\n";
	oss << "Content-Length: " << content.size() << "\r\n";
	oss << "\r\n";
	oss << content;
	
	std::string output = oss.str();
	size = output.size() + 1;

	sendToClient(clientSocket, output.c_str(), size);
}