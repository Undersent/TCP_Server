//
// Created by rafal on 15.09.17.
//

#include <memory>
#include <iostream>
#include "MessageChuckNorrisJoke.h"
#include "../REST/RestApi.h"

std::string MessageChuckNorrisJoke::getMessage(std::string &message) {
    return makeRestGetRequestToObtainJoke();
}

std::string MessageChuckNorrisJoke::makeRestGetRequestToObtainJoke() {
    RestApi restApi;
    return obtainJokeFromAnswer(restApi.get());

}

std::string MessageChuckNorrisJoke::obtainJokeFromAnswer(std::string answer){
    return answer.substr(answer.find("joke")+8,answer.find("\"categories\"")-3 -(answer.find("joke")+8));
}
