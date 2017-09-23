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
    const std::string getName()const override {return "MessageChuckNorrisJoke";} ;
    
private:
    std::string makeRestGetRequestToObtainJoke() const;
    std::string obtainJokeFromAnswer(std::string answer) const;
};


#endif //PROJECT_MESSAGECHUCKNORRISJOKE_H
