//
// Created by rafal on 14.09.17.
//

#include "MessageClient.h"
#include "MessageSame.h"
#include "MessageCorrect.h"
#include <locale>
std::string MessageClient::getMessage() {
    return _message->getMessage(_cleanMessage);
}

void MessageClient::setMessageStrategy(std::string& message) {
    if(message[0] != '['){
        _message = std::make_unique<MessageSame>(MessageSame());
        _cleanMessage = message;
    }
    if (message.substr(0, 7) == "[check]") {
        _message = std::make_unique<MessageCorrect>(MessageCorrect());
        cleanMessage(message, 7);
    } //[check]

}

const std::string &MessageClient::getCleanMessage() const {
    return _cleanMessage;
}

void MessageClient::cleanMessage(std::string &message, unsigned int noOfDeletedChar) {
    if(message.size()) {
        _cleanMessage = message.substr(noOfDeletedChar);//to the end
        auto &f = std::use_facet<std::ctype<char>>(std::locale());
        f.toupper(const_cast<char *>(_cleanMessage.data()), _cleanMessage.data() + _cleanMessage.size());
    }
}

