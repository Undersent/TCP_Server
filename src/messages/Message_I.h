//
// Created by rafal on 14.09.17.
//

#ifndef PROJECT_MESSAGE_H
#define PROJECT_MESSAGE_H

#include <string>
//strategy pattern
class Message_I {
public:
    Message_I() = default;
    virtual std::string getMessage(std::string& message) = 0;
};


#endif //PROJECT_MESSAGE_H
