//
// Created by rafal on 15.09.17.
//

#include <memory>
#include <iostream>
#include "MessageChuckNorrisJoke.h"
#include "../REST/RestApi.h"
#include <exception>

std::string MessageChuckNorrisJoke::getMessage(std::string &message) {
    return makeRestGetRequestToObtainJoke();
}

std::string MessageChuckNorrisJoke::makeRestGetRequestToObtainJoke()const {
    RestApi restApi{};
    if(!restApi.prepareSocketConnection("193.190.253.234", 80)){
        return "error obtaining joke";
    }
     char msg[] = "GET /jokes/random HTTP/1.1\r\n"
             "Host: api.icndb.com\r\n"
             "Accept: (application/json|text/plain)\r\n"
             "\r\n";
    restApi.setMsg(msg);
    return obtainJokeFromAnswer(restApi.get());

}

std::string MessageChuckNorrisJoke::obtainJokeFromAnswer(std::string answer) const{
    try {
        return answer.substr(answer.find("joke") + 8, answer.find("\"categories\"") - 3 - (answer.find("joke") + 8));
    }catch(std::exception& e)
    {
        return "Cant connect to the internet";
    }
}
