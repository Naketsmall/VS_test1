#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <tchar.h>
#include <ws2tcpip.h>
#include <iostream>
#include "ServerSocket.h"
#include <thread>


void setupWSA() {
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "WSA Startup Error" << std::endl;
		exit(1);
	}
}
/*

void run(std::string threadName, int* g, int f) {
	for (int i = 0; i < 10; i++) {
		*g += f;
		std::cout << *g;
	}
}

int main() {
	int d = 0;
	std::thread tA(run, "A", &d, 1);
	std::thread tB(run, "\tB", &d, -1);
	tA.join();
	tB.join();
}
*/


int main() {
	setupWSA();
	
	
	ServerSocket(4030).startServer();


	return 0;
}
