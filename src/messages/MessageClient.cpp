//
// Created by rafal on 14.09.17.
//

#include "MessageClient.h"
#include "MessageSame.h"
#include "MessageCorrect.h"

std::string MessageClient::getMessage() {
    return _message->getMessage(_cleanMessage);
}

void MessageClient::setMessageStrategy(std::string& message) {
    if(message[0] != '['){
        _message = std::make_shared<MessageSame>(MessageSame());
    }
    if (message.substr(0, 7) == "[check]") {
        _message = std::make_shared<MessageCorrect>(MessageCorrect(_tst));
        _cleanMessage = message.substr(message.find("[check]"));
    } //[check]

}

const std::string &MessageClient::getCleanMessage() const {
    return _cleanMessage;
}

