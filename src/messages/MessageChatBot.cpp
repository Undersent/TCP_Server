//
// Created by rafal on 20.09.17.
//


#include <iostream>
#include <algorithm>
#include "MessageChatBot.h"



std::string MessageChatBot::getMessage(std::string &message) {

    return makeRestGetRequestToObtainRespondFromBot(message);
}

std::string MessageChatBot::makeRestGetRequestToObtainRespondFromBot(std::string &message) const {
    RestApi restApi{};
    if(!restApi.prepareSocketConnection("127.0.0.1", 5000)){
        return "error obtaining a respond from bot ;(. He's busy!";
    }
    std::string getRequest = createGetRequest(message);
    std::string msg = "GET /get/"+ getRequest +" HTTP/1.1\r\n"
            "Host: localhost:5000\r\n"
            "Accept: (application/json|text/plain/html)\r\n"
            "\r\n";
    restApi.setMsg(msg);
    return obtainRespondFromAnswer(restApi.get());
}

std::string MessageChatBot::obtainRespondFromAnswer(std::string answer) const {
    std::cout<<answer<<"\n";
    try {
        std::string temp = answer.substr(answer.find("GMT") + 7, answer.find("[       OK ]") - 12 - (answer.find("GMT") + 8));
        return temp;
    }catch(std::exception& e)
    {
        return "Cant connect to the internet!";
    }

}

std::string MessageChatBot::createGetRequest(std::string &message) const {
    std::string msgWithoutSpaces{};
    for (const char i : message) {
        if(i == ' '){
            msgWithoutSpaces+= '%';
            msgWithoutSpaces+='2';
            msgWithoutSpaces+='0';
        }else
        {
            msgWithoutSpaces+= i;
        }
    }
    return msgWithoutSpaces;
}
