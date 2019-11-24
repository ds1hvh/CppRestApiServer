#pragma once

#include<iostream>
#include<WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

class TcpListener {

public :
	
	TcpListener(const char* ipAddress, int port) :
		m_ipAddress(ipAddress), m_port(port) { }

	// Initialize the listener
	int init();

	// Run the listener
	int run();

protected:

	// Handler for client connections
	void onClientConnected();

	// Handler for client disconnections
	void onClientDisconnected();

	// Send a message to a client
	void sendToClient(int clientSocket, const char* msg, int length);

private:

	const char* m_ipAddress;	// IP Address server will run on
	int			m_port;			// Port # for the web service
	int			m_socket;		// Internal FD for the listening socket
	fd_set		m_master;		// Master file descriptor set
};