//
// Created by rafal on 23.09.17.
//

#include <gtest/gtest.h>
#include "../../src/messages/MessageChuckNorrisJoke.h"


class ChuckNorrisMessageTest : public ::testing::Test {
public:
    MessageChuckNorrisJoke messageChuckNorrisJoke;
    ChuckNorrisMessageTest() = default;
    ~ChuckNorrisMessageTest() override  = default;

    void SetUp() override{
    }

    void TearDown() override{
    }
};



TEST_F(ChuckNorrisMessageTest, test_eq) {
    std::string inChuckNorrisJokeMessageIsNotImportant{};
    std::string respond = messageChuckNorrisJoke.getMessage(inChuckNorrisJokeMessageIsNotImportant);
    ASSERT_TRUE(respond.size()>0);

}