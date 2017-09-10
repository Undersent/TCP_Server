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
class ConnectionHandler : public Thread
{
    WorkerQueue<WorkItem*>& queue;

public:
    explicit ConnectionHandler(WorkerQueue<WorkItem*>& queue) : queue(queue) {}

    void* run() override {
        // Remove 1 item at a time and process it. Blocks if no items are
        // available to process.
        for (int i{};; i++) {
            if (i == 0) {
                WorkItem* item = queue.remove();
                TCPStreamData* stream = item->getStream();

                // Echo messages back the client until the connection is
                // closed
                char input[256];
                std::vector<std::string> tokens{};
                ssize_t len;
                len = stream->receive(input, sizeof(input)-1);
                input[len] = NULL;
                char * token;
                printf ("Splitting string \"%s\" into tokens:\n",input);
                token = strtok (input," []");
                while (token != NULL)
                {
                    printf ("%s\n",token);
                    tokens.emplace_back((token));
                    token = strtok (NULL, " []");
                }

                try {
                    RSA::RSA rsa(atol(tokens[0].c_str()), atol(tokens[1].c_str()));
                    //rsa.set_converserPublicKey(rsa1.get_publicKey());
                    char const *output = (std::to_string(rsa.get_publicKey())+'\0').c_str() ;
                    stream->send(output,sizeof(output)-1 );
                    std::cout<<"thread "<< (long unsigned int)self()
                             << " echoed "<< output << " back to the client\n";
                }
                catch (const std::out_of_range& oor) {
                    std::cerr << "Out of Range error: " << oor.what() << '\n';
                }

                //len = sizeof(output)-1;
                //output[len] = NULL;
                //stream->send(output, len);
                //std::cout<<"wyslalem "<<output;
            }else{
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
                             << " echoed "<< input << " back to the client\n";

                }
                delete item;
            }

        }

        // Should never get here
        return nullptr;
    }
};
#endif //PROJECT_CONNECTIONHANDLER_H
