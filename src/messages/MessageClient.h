//
// Created by rafal on 14.09.17.
//

#ifndef PROJECT_MESSAGECLIENT_H
#define PROJECT_MESSAGECLIENT_H


#include <memory>
#include <utility>
#include "Message_I.h"
#include "MessageSame.h"
#include "../../AlgAndDataStructures/TernarySearchTree.h"

class MessageClient {
    std::unique_ptr<Message_I> _message = nullptr;
    //TST::TernarySearchTree _tst;
    std::string _cleanMessage{};


public:
    explicit MessageClient() =default;

    explicit MessageClient(std::unique_ptr<Message_I> message) : _message(std::move(message)){}

    std::string getMessage();

    void setMessageStrategy(std::string& message);

    const std::string &getCleanMessage() const;

    void prepareMessageToCheckInDictionary(std::string &_message, unsigned int noOfDeletedChar);
};


#endif //PROJECT_MESSAGECLIENT_H