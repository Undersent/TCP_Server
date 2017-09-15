//
// Created by rafal on 14.09.17.
//

#include "MessageClient.h"
#include "MessageSame.h"
#include "MessageCorrect.h"
#include "MessageChuckNorrisJoke.h"
#include <locale>
std::string MessageClient::getMessage() {
    return _message->getMessage(_cleanMessage);
}

void MessageClient::setMessageStrategy(std::string& message) {
    if(message[0] != '['){
        _message = std::make_unique<MessageSame>(MessageSame());
        _cleanMessage = message;
    } //empty
    else if (message.substr(0, 7) == "[check]") {
        _message = std::make_unique<MessageCorrect>(MessageCorrect());
        prepareMessageToCheckInDictionary(message, 7);
    } //[check]
    else if (message.substr(0,6) == "[joke]") {
        _message = std::make_unique<MessageChuckNorrisJoke>(MessageChuckNorrisJoke());
        //the're is no point in set _cleanMessage up cause ChuckNorisJoke doesnt use it
    }

}

const std::string &MessageClient::getCleanMessage() const {
    return _cleanMessage;
}

void MessageClient::prepareMessageToCheckInDictionary(std::string &message, unsigned int noOfDeletedChar) {
    if(!message.empty()) {
        _cleanMessage = message.substr(noOfDeletedChar);//to the end
        auto &f = std::use_facet<std::ctype<char>>(std::locale());
        f.toupper(const_cast<char *>(_cleanMessage.data()), _cleanMessage.data() + _cleanMessage.size());
    }
}

