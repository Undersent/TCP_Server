//
// Created by rafal on 14.09.17.
//

#ifndef PROJECT_MESSAGESAME_H
#define PROJECT_MESSAGESAME_H

#include <string>
#include "Message_I.h"
//only for testing
class MessageSame : public Message_I{

public:
    MessageSame() = default;
    std::string getMessage(std::string& message) override ;
    const std::string getName()const override {return "MessageSame";};
};


#endif //PROJECT_MESSAGESAME_H
