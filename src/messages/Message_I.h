//
// Created by rafal on 14.09.17.
//

#ifndef PROJECT_MESSAGE_H
#define PROJECT_MESSAGE_H

#include <string>
//strategy pattern
class Message_I {
public:
    virtual std::string getMessage(std::string& message) = 0;
    virtual const std::string getName() const = 0 ;
};


#endif //PROJECT_MESSAGE_H
