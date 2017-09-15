//
// Created by rafal on 15.09.17.
//

#ifndef PROJECT_MESSAGECHUCKNORRISJOKE_H
#define PROJECT_MESSAGECHUCKNORRISJOKE_H


#include "Message_I.h"

class MessageChuckNorrisJoke : public Message_I{
public:
    MessageChuckNorrisJoke()=default;
    std::string getMessage(std::string& message) override ;

    std::string makeRestGetRequestToObtainJoke();
    std::string obtainJokeFromAnswer(std::string answer);
};


#endif //PROJECT_MESSAGECHUCKNORRISJOKE_H
