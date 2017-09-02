//
// Created by rafal on 01.09.17.
//

#ifndef TCP_SERVER_ACCEPTORTOTCPSERVER_H
#define TCP_SERVER_ACCEPTORTOTCPSERVER_H


#include "TCPStreamData.h"

class AcceptorToTCPServer
{
private:
    int listeningSocketDescriptor{};
    std::string address{};
    int port{};
    bool isListening{};

public:
    explicit AcceptorToTCPServer(int port, const char* address="");
    virtual ~AcceptorToTCPServer();

    int start();
    TCPStreamData* accept() const;

private:
    AcceptorToTCPServer() = default;
};


#endif //TCP_SERVER_ACCEPTORTOTCPSERVER_H
