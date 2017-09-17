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
