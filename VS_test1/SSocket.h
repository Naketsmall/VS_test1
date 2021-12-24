#pragma once
#include <WinSock2.h>
#include <string>
class SSocket {
protected:

	bool running;
	int sizeofaddr;

	SOCKET this_s;
	SOCKADDR_IN addr;


public:

	SSocket(unsigned short port);
	~SSocket();
	
	unsigned short getPort();	
	
	virtual bool sendMessage() = 0;
	virtual bool isRunning() = 0;
	
};

