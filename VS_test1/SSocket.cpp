#include "SSocket.h"
#include <tchar.h>
#include <ws2tcpip.h>

#pragma warning(disable: 4996)

SSocket::SSocket(unsigned short port)
{
	sizeofaddr = sizeof(addr);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;

	this_s = socket(AF_INET, SOCK_STREAM, NULL);
	running = false;
}

SSocket::~SSocket(){}


unsigned short SSocket::getPort()
{
	return  addr.sin_port;
}
