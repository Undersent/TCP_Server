//
// Created by rafal on 15.09.17.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <zconf.h>
#include <arpa/inet.h>
#include <memory>
#include <thread>
#include "RestApi.h"

std::string RestApi::get() {
    const unsigned int MAX_SIZE=1024;
    char answ[MAX_SIZE];
    send(_socket,_msg.c_str(),_msg.length()+1,0);
    ssize_t len{1};
    std::string respond{};
    while(len != 0){
        len = recv(_socket, answ, MAX_SIZE, 0);
        answ[len] = NULL;
        respond+=answ;
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); //cause localhost is too fast...
    }
    close(_socket);
    if(len < 0)
    {
        //error
    }
    return respond;
}

bool RestApi::prepareSocketConnection(const std::string& ipAdress, const int port) {
    int error;
    struct sockaddr_in addr;


    if((_socket = socket(AF_INET,SOCK_STREAM,0))<0)
    {
        close(_socket);
        //TODO THROW EXCEPTION
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(PF_INET,(ipAdress.c_str()),&addr.sin_addr);

    error = connect(_socket,(sockaddr*)&addr,sizeof(addr));
    if(error!=0)
    {
        close(_socket);
        //todo throw exception
        return false;
    }
    return true;
}

void RestApi::setMsg(const std::string &msg) {
    RestApi::_msg = msg;
}

void RestApi::post() {

}

void RestApi::put() {

}

void RestApi::deleteF() {

}



