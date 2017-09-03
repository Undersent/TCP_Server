//
// Created by rafal on 03.09.17.
//

#ifndef PROJECT_CONNECTIONHANDLER_H
#define PROJECT_CONNECTIONHANDLER_H

#include "TCPStreamData.h"
#include "../data_transfer/WorkItem.h"
#include "../data_transfer/WorkerQueue.h"
#include "../multithreading/Thread.h"

class ConnectionHandler : public Thread
{
    WorkerQueue<WorkItem*>& queue;

public:
    explicit ConnectionHandler(WorkerQueue<WorkItem*>& queue) : queue(queue) {}

    void* run() override {
        // Remove 1 item at a time and process it. Blocks if no items are
        // available to process.
        for (int i{};; i++) {
            std::cout<<"thread "<< (long unsigned int)self()
                    <<" loop "<< i <<" - waiting for item...\n";

            WorkItem* item = queue.remove();
            std::cout<<"thread "<< (long unsigned int)self()
                     <<" loop "<< i << " - got one item \n";

            TCPStreamData* stream = item->getStream();

            // Echo messages back the client until the connection is
            // closed
            char input[256];
            ssize_t len;
            while ((len = stream->receive(input, sizeof(input)-1)) > 0 ){
                input[len] = NULL;
                stream->send(input, len);
                std::cout<<"thread "<< (long unsigned int)self()
                        << "echoed "<< input << "back to the client\n";

            }
            delete item;
        }

        // Should never get here
        return nullptr;
    }
};
#endif //PROJECT_CONNECTIONHANDLER_H
