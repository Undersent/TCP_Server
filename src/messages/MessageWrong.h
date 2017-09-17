//
// Created by rafal on 17.09.17.
//

#ifndef PROJECT_MESSAGEWRONG_H
#define PROJECT_MESSAGEWRONG_H


#include "Message_I.h"

class MessageWrong : public Message_I{
public:
    MessageWrong() = default;
    std::string getMessage(std::string& message) override ;
    const std::string getName()const override {return "MessageSame";};
};


#endif //PROJECT_MESSAGEWRONG_H
