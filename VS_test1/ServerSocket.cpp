#include "ServerSocket.h"
#include <iostream>
#include <thread>

ServerSocket::ServerSocket(unsigned short port)
	: SSocket(port)
{
	clients = {};
}

void ServerSocket::updateConnections() {
	SOCKET newConnection;
	char msg[256] = "{code:1, msg:hello}\n";
	while (running) {
		bind(this_s, (SOCKADDR*)&addr, sizeof(addr));
		listen(this_s, SOMAXCONN);
		newConnection = accept(this_s, (SOCKADDR*)&addr, &sizeofaddr);

		if (newConnection == 0) {
			std::cout << "Error #2\n";
		}
		else {
			clients.push_back(newConnection);
			std::cout << "Client Connected!\n";
			send(clients[clients.size()-1], msg, sizeof(msg), NULL);

			std::thread clientIteraction(&ServerSocket::updateMessages, this, clients[clients.size() - 1]);
			clientIteraction.join();

		}
	}
}


void ServerSocket::updateMessages(SOCKET client) {
	char msg[256];
	recv(client, msg, sizeof(msg), NULL);
	for (SOCKET send_to : clients) {
		send(send_to, msg, sizeof(msg), NULL);
	}
	
}

bool ServerSocket::startServer()
{//TODO: rewrite function
	if (running)
		return false;
	else {
		running = true;
		std::cout << "Waiting for connection..." << std::endl;

		std::thread clientsRoom(&ServerSocket::updateConnections, this);

		clientsRoom.join();
		

		std::cout << 1 << std::endl;

		return true;
	}
}

bool ServerSocket::stopServer()
{ // TODO: finish up this too
	//shutdown(this_s, 0);
	closesocket(this_s);
	running = false;
	return boolean(1);
}

bool ServerSocket::isRunning()
{ // Damn, that works right
	return running;
}

bool ServerSocket::sendMessage()
{// TODO
	return boolean(1);
}
