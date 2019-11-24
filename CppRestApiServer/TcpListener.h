#pragma once

class TcpListener {

public :

protected:

private:

	const char* m_ipAddress;	// IP Address server will run on
	int			m_port;			// Port # for the web service
	int			m_socket;		// Internal FD for the listening socket
};