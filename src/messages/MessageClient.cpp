//
// Created by rafal on 14.09.17.
//

#include "MessageClient.h"
#include "MessageSame.h"
#include "MessageCorrect.h"
#include "MessageChuckNorrisJoke.h"
#include "MessageWrong.h"
#include <locale>
#include <algorithm>

std::string MessageClient::getMessage() {
    std::string messageToClient = _message->getMessage(_cleanMessage);
    if(messageToClient.empty()) {
        return "sth went wrong";
    }else
    return _message->getMessage(_cleanMessage);
}

bool MessageClient::isMessageObjectCreatedYet(const std::string& className){
    auto it = find_if(_messagesObjects.begin(), _messagesObjects.end(),
                      [&className](const auto& obj) {
                          return obj->getName() == className;});
    if (it != _messagesObjects.end())
    {
        _message = *it;
        return true;
    }else
        return false;
}

void MessageClient::setMessageStrategy(std::string& message) {
    _message = nullptr;
    if(message[0] != '['){
        if (!isMessageObjectCreatedYet("MessageSame")) {
            _message = std::make_shared<MessageSame>(MessageSame{});
            _messagesObjects.push_back(_message);
        }
        _cleanMessage = message;
    } //empty
    else if (message.substr(0, 7) == "[check]") {

        if(!isMessageObjectCreatedYet("MessageCorrect")){
            _message = std::make_shared<MessageCorrect>(MessageCorrect{});
            _messagesObjects.push_back(_message);
        }
        prepareMessageToCheckInDictionary(message, 7);

    } //[check]
    else if (message.substr(0,6) == "[joke]") {
        if(!isMessageObjectCreatedYet("MessageChuckNorrisJoke")){
            _message = std::make_shared<MessageChuckNorrisJoke>(MessageChuckNorrisJoke{});
            _messagesObjects.push_back(_message);
        }
        //the're is no point in set _cleanMessage up cause ChuckNorrisJoke doesnt use it
    }else{
        if(!isMessageObjectCreatedYet("MessageWrong")){
            _message = std::make_shared<MessageWrong>(MessageWrong{});
            _messagesObjects.push_back(_message);
        }
        //_cleanMessage = "Wrong command";
    }
}

const std::string &MessageClient::getCleanMessage() const {
    return _cleanMessage;
}

void MessageClient::prepareMessageToCheckInDictionary(const std::string &message,
                                                      unsigned int noOfDeletedChar) {
    if(!message.empty()) {
        _cleanMessage = message.substr(noOfDeletedChar);//to the end
        auto &f = std::use_facet<std::ctype<char>>(std::locale());
        f.toupper(const_cast<char *>(_cleanMessage.data()), _cleanMessage.data() + _cleanMessage.size());
    }
}

