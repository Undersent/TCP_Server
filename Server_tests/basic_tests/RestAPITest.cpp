//
// Created by rafal on 15.09.17.
//

#include <gtest/gtest.h>
#include "../../src/REST/RestApi.h"
#include "../../src/REST/RestApi.cpp"
#include "../../src/messages/MessageChuckNorrisJoke.h"
#include "../../src/messages/MessageChuckNorrisJoke.cpp"

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

    std::cout<<"     "<<joker.getMessage(foo);
}