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
#include "RestApi.h"

std::string RestApi::get() {
    int s, error;
    struct sockaddr_in addr;
    const unsigned int MAX_SIZE=1024;

    if((s = socket(AF_INET,SOCK_STREAM,0))<0)
    {
        close(s);
        //TODO THROW EXCEPTION
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    inet_pton(PF_INET,"193.190.253.234",&addr.sin_addr);

    error = connect(s,(sockaddr*)&addr,sizeof(addr));
    if(error!=0)
    {
        close(s);
        //TODO THROW EXCEPTION
    }
    char msg[] = "GET /jokes/random HTTP/1.1\r\n"
            "Host: api.icndb.com\r\n"
            "Accept: (application/json|text/plain)\r\n"
            "\r\n";
    char answ[MAX_SIZE];

    send(s,msg,sizeof(msg),0);
    ssize_t len;
    len = recv(s, answ, MAX_SIZE, 0);
    answ[len] = NULL;

    if(len < 0)
    {
        //error
    }
    return std::string{answ};
}

void RestApi::post() {

}

void RestApi::put() {

}

void RestApi::deleteF() {

}
