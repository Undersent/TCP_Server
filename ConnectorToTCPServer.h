//
// Created by rafal on 01.09.17.
//

#ifndef TCP_SERVER_CONNECTORTOTCPSERVER_H
#define TCP_SERVER_CONNECTORTOTCPSERVER_H


#include "TCPStreamData.h"

class ConnectorToTCPServer {

public:
    TCPStreamData* makeConnection(int port, const char* server) const;
private:
    int getHostName(const char* host, struct in_addr* addr) const;

};


#endif //TCP_SERVER_CONNECTORTOTCPSERVER_H
