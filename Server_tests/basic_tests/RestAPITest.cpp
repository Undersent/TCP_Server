//
// Created by rafal on 15.09.17.
//

#include <gtest/gtest.h>
#include "../../src/REST/RestApi.h"
#include "../../src/REST/RestApi.cpp"
#include "../../src/messages/MessageChuckNorrisJoke.h"
#include "../../src/messages/MessageChuckNorrisJoke.cpp"
#include "../../src/messages/MessageChatBot.h"
#include "../../src/messages/MessageChatBot.cpp"

class RestAPITest : public ::testing::Test {

};


TEST_F(RestAPITest, getRequest) {
    RestApi restApi;
    std::string a = restApi.get();
    std::cout<<a;
}

TEST_F(RestAPITest, getJoke) {
    MessageChuckNorrisJoke joker;
    std::string foo{"foo"};
    std::cout<<"\n\n\n";
    std::cout<<"     "<<joker.getMessage(foo);
}

TEST_F(RestAPITest, getChatBotRespond) {
    MessageChatBot bot;
    std::string foo{"Where's the point in living?"};
    std::cout<<"\n\n\n";
    std::cout<<"     "<<bot.getMessage(foo);
}

/*
 *     char msg[] = "GET /get/how%20are%20you? HTTP/1.1\r\n"
            "Host: localhost:5000\r\n"
            "Accept: (application/json|text/plain/html)\r\n"
            "\r\n";
 */