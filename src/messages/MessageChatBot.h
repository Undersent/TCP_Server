//
// Created by rafal on 20.09.17.
//

#ifndef PROJECT_MESSAGECHATBOT_H
#define PROJECT_MESSAGECHATBOT_H
#include "Message_I.h"

#include "../REST/RestApi.h"

class MessageChatBot : public Message_I{
public:
    
    MessageChatBot() = default;
    std::string getMessage(std::string& message) override ;
    const std::string getName() const override {return "MessageChatBot";};
    
private:
    
    std::string makeRestGetRequestToObtainRespondFromBot(std::string &message) const;
    std::string obtainRespondFromAnswer(std::string answer) const;
    std::string createGetRequest(std::string &message) const;
};


#endif //PROJECT_MESSAGECHATBOT_H
