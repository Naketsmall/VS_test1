#pragma once
#include "SSocket.h"
#include <vector>

class ServerSocket :
    public SSocket
{
private: 
    std::vector<SOCKET> clients;

public:
    ServerSocket(unsigned short port);

    void updateConnections();

    void updateMessages(SOCKET client);

    bool startServer();
    bool stopServer();

    bool isRunning();
    bool sendMessage();
};
