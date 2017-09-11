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
#include "memory"
#include <vector>

class ConnectionHandler : public Thread {
    WorkerQueue<WorkItem *> &queue;
    std::unique_ptr<RSA::RSA> rsa;

public:
    explicit ConnectionHandler(WorkerQueue<WorkItem *> &queue) : queue(queue) {}

    void prepareRSAConnection( TCPStreamData* stream) {
        //TODO: CHANGE CODE TO MORE MODERN VERSION. ITS NOT OBVIOUS HOW TO USE SMART POINTERS HERE
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
            //RSA::RSA rsa(atol(tokens[0].c_str()), atol(tokens[1].c_str()));
            rsa = std::make_unique<RSA::RSA>(RSA::RSA(atol(tokens[0].c_str()), atol(tokens[1].c_str())));
            char const *output = (std::to_string(rsa->get_publicKey()) + '\0').c_str();
            stream->send(output, sizeof(output) - 1);
            std::cout << "thread " << (long unsigned int) self()
                      << " echoed " << output << " back to the client\n";
            //delete output;
        }
        catch (const std::out_of_range &oor) {
            std::cerr << "Out of Range error: " << oor.what() << '\n';
            delete token;

        }
        //delete token;

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
                //std::cout<<"GOT "<<input;
                //std::string decodedInput = rsa->decryptString(input);
                //cos tu robi ze stringiem aby dostac output;
                std::cout<<"after decryption "<<rsa->decryptString(input)<<"\n";

                //const char* a = rsa->encryptString(input).c_str();
                stream->send(rsa->encryptString(rsa->decryptString(input)).c_str(), len);
                std::cout << "thread " << (long unsigned int) self()
                          << " echoed " << rsa->encryptString(rsa->decryptString(input))
                          << " back to the client\n";

            }
            delete item;
        }
        // Should never get here
        return nullptr;
    }
};

#endif //PROJECT_CONNECTIONHANDLER_H
