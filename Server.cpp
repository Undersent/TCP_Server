//
// Created by rafal on 02.09.17.
//

#include <iostream>
#include "TCPStreamData.h"
#include "AcceptorToTCPServer.h"


using namespace std;
const char endMessage[256] = ":!q";

int main(int argc, char** argv)
{
    if (argc < 2 || argc > 4) {
        std::cout<<"usage: server <port> [<ip>]\n";
        return 0;
    }

    TCPStreamData* stream = nullptr;
    AcceptorToTCPServer* acceptor = nullptr;
    if (argc == 3) {
        acceptor = new AcceptorToTCPServer(atoi(argv[1]), argv[2]);
    }
    else {
        acceptor = new AcceptorToTCPServer(atoi(argv[1]));
    }
    if (acceptor->start() == 0) {

        while (1) {
            stream = acceptor->accept();
            if (stream != NULL ) {
                size_t len;
                char line[256];
                while ((len = stream->receive(line, sizeof(line))) > 0) {
                    line[len] = NULL;

                    if(line == endMessage){
                        break;
                    }
                    printf("received - %s\n", line);
                    stream->send(line, len);
                }
                delete stream;
            }
        }
    }
    perror("Could not start the server");
    exit(-1);
}