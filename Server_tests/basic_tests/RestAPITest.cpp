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
public:
    RestApi restApi;
    RestAPITest() = default;
    virtual ~RestAPITest()  = default;

    void SetUp() override{
    }

    void TearDown() override{
    }
};


TEST_F(RestAPITest, getRequest) {
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
