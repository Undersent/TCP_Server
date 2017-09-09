//
// Created by rafal on 02.09.17.
//

#include <iostream>
#include "TCPStreamData.h"
#include "AcceptorToTCPServer.h"

#include "../data_transfer/WorkerQueue.h"
#include "../data_transfer/WorkItem.h"
#include "ConnectionHandler.h"
#include "../../AlgAndDataStructures/RSA.h"


int main(int argc, char** argv)
{

    // Process command line arguments
    if ( argc < 3 || argc > 4 ) {
        printf("usage: %s <workers> <port> <ip>\n", argv[0]);
        exit(-1);
    }
    int workers = atoi(argv[1]);
    int port = atoi(argv[2]);
    std::string ip;
    if (argc == 4) {
        ip = argv[3];
    }

    // Create the queue and consumer (worker) threads
    WorkerQueue<WorkItem*>  queue;
    for (int i = 0; i < workers; i++) {
        ConnectionHandler * handler;
        handler = new ConnectionHandler(queue);
        handler->start();
    }

    // Create an acceptor then start listening for connections
    WorkItem* item;
    AcceptorToTCPServer* connectionAcceptor;
    if (ip.length() > 0) {
        connectionAcceptor = new AcceptorToTCPServer(port, (char*)ip.c_str());
    }
    else {
        connectionAcceptor = new AcceptorToTCPServer(port);
    }
    if ( connectionAcceptor->start() != 0) {
        printf("Could not create an connection acceptor\n");
        exit(1);
    }

    // Add a work item to the queue for each connection
    while (1) {
        TCPStreamData* connection = connectionAcceptor->accept();
        if (!connection) {
            printf("Could not accept a connection\n");
            continue;
        }
        item = new WorkItem(connection);
        queue.add(item);
    }

    // Should never get here
    return -1;
}