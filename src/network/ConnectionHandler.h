//
// Created by rafal on 03.09.17.
//

#ifndef PROJECT_CONNECTIONHANDLER_H
#define PROJECT_CONNECTIONHANDLER_H

#include <cstring>
#include "TCPStreamData.h"
#include "../data_transfer/WorkItem.h"
#include "../data_transfer/WorkerQueue.h"
#include "../multithreading/Thread.h"
#include "../../AlgAndDataStructures/RSA.h"
#include <stdio.h>

#include <vector>

class ConnectionHandler : public Thread {
    WorkerQueue<WorkItem *> &queue;

public:
    explicit ConnectionHandler(WorkerQueue<WorkItem *> &queue) : queue(queue) {}

    void prepareRSAConnection( TCPStreamData* stream) {

        std::vector<std::string> tokens{};
        char input[256];
        ssize_t len;
        char *token;
        len = stream->receive(input, sizeof(input)-1);
        input[len] = NULL;
        printf("Splitting string \"%s\" into tokens:\n", input); //TODO: Exception
        token = strtok(input, " []");
        while (token != NULL) {
            printf("%s\n", token);
            tokens.emplace_back((token));
            token = strtok(NULL, " []");
        }

        try {
            RSA::RSA rsa(atol(tokens[0].c_str()), atol(tokens[1].c_str()));
            char const *output = (std::to_string(rsa.get_publicKey()) + '\0').c_str();
            stream->send(output, sizeof(output) - 1);
            std::cout << "thread " << (long unsigned int) self()
                      << " echoed " << output << " back to the client\n";
        }
        catch (const std::out_of_range &oor) {
            std::cerr << "Out of Range error: " << oor.what() << '\n';
        }
    }

    void *run() override {
        // Remove 1 item at a time and process it. Blocks if no items are
        // available to process.

        for (int i{}, j{};; i++) {
            std::cout << "thread " << (long unsigned int) self()
                      << " loop " << i << " - waiting for item...\n";
            WorkItem *item = queue.remove();
            std::cout << "thread " << (long unsigned int) self()
                      << " loop " << i << " - got one item \n";
            TCPStreamData *stream = item->getStream();
            prepareRSAConnection( stream);
            char input[256];
            ssize_t len;
            while ((len = stream->receive(input, sizeof(input) - 1)) > 0) {
                input[len] = NULL;
                stream->send(input, len);
                std::cout << "thread " << (long unsigned int) self()
                          << " echoed " << input << " back to the client\n";

            }
            delete item;
        }
        // Should never get here
        return nullptr;
    }
};

#endif //PROJECT_CONNECTIONHANDLER_H
