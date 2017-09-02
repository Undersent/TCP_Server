//
// Created by rafal on 01.09.17.
//

#include <zconf.h>
#include <cstring>
#include <arpa/inet.h>
#include "AcceptorToTCPServer.h"
#include <iostream>
AcceptorToTCPServer::AcceptorToTCPServer(int port, const char *address) :
listeningSocketDescriptor(0), port(port), address(address), isListening(false){}

AcceptorToTCPServer::~AcceptorToTCPServer() {
    if(listeningSocketDescriptor > 0){
        close(listeningSocketDescriptor);
    }
}

int AcceptorToTCPServer::start()  {
    if (isListening){
        return 0;
    }
    listeningSocketDescriptor = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addressIn;

    memset(&addressIn, 0, sizeof(addressIn));
    addressIn.sin_family = PF_INET;
    addressIn.sin_port = htons(port);
    if(!address.empty()){
        inet_pton(PF_INET, address.c_str(), &(addressIn.sin_addr));
    }else{
        addressIn.sin_addr.s_addr = INADDR_ANY;
    }
    int optval = 1;
    setsockopt(listeningSocketDescriptor, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval );

    int result = bind(listeningSocketDescriptor,
                      (struct sockaddr*)&addressIn, sizeof(addressIn));
    if(result != 0){
        perror("failed to bind()");
        return result;
    }

    result = listen(listeningSocketDescriptor, 5);
    if(result != 0) {
        perror("listen () failed");
        return result;
    }
    isListening = true;
    return result;

}

TCPStreamData* AcceptorToTCPServer::accept() const {
    if (!isListening) {
        return nullptr;
    }

    struct sockaddr_in addressIn;
    socklen_t len = sizeof(addressIn);
    memset(&addressIn, 0, sizeof(addressIn));
    int socketDescriptor = ::accept(listeningSocketDescriptor, (struct sockaddr*)&addressIn, &len);
    if (socketDescriptor  < 0) {
        perror("accept() failed");
        return nullptr;
    }
    return new TCPStreamData(socketDescriptor , &addressIn);
}
