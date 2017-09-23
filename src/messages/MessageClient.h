//
// Created by rafal on 14.09.17.
//

#ifndef PROJECT_MESSAGECLIENT_H
#define PROJECT_MESSAGECLIENT_H


#include <memory>
#include <utility>
#include <vector>
#include "Message_I.h"
#include "MessageSame.h"
#include "../../AlgAndDataStructures/TernarySearchTree.h"

class MessageClient {
    std::shared_ptr<Message_I> _message = nullptr;
    std::string _cleanMessage{};
    std::vector<std::shared_ptr<Message_I>> _messagesObjects{};


public:
    explicit MessageClient() = default;

    explicit MessageClient(std::shared_ptr<Message_I>& message) : _message(std::move(message)){}

    std::string getMessage();

    void setMessageStrategy(std::string& message);

    const std::string &getCleanMessage() const;

private:
    bool isMessageObjectCreatedYet(const std::string& className);

};


#endif //PROJECT_MESSAGECLIENT_H
