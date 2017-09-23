//
// Created by rafal on 15.09.17.
//


#include <gtest/gtest.h>
#include "../../src/messages/MessageClient.h"
#include "../../AlgAndDataStructures/SpellCorrector.h"
#include "../../AlgAndDataStructures/SpellCorrector.cpp"

class SpellCorrectorTest : public ::testing::Test {
public:
    SpellCorrector spellCorrector;
    SpellCorrectorTest() = default;
    virtual ~SpellCorrectorTest()  = default;

    void SetUp() override{
    }

    void TearDown() override{
    }
};

TEST_F(SpellCorrectorTest,computeLevenshteinDistanceTest){
    std::string word1 = "cattable";
    std::string word2 = "cat";
    std::string word3 = "cbt";
    ASSERT_EQ(spellCorrector.computeLevenshteinDistance(word1,word2),5);
    ASSERT_EQ(spellCorrector.computeLevenshteinDistance(word3,word2),1);
}


TEST_F(SpellCorrectorTest, correctMessage){
    spellCorrector.getTST()->insert("cat", "123");
    spellCorrector.getTST()->insert("cata", "123");
    spellCorrector.getTST()->insert("cattable", "123");
    spellCorrector.getTST()->insert("myDream", "123");
    spellCorrector.correctWord("cat");
    std::string correctedMessage;
    while (!spellCorrector.getWordsPQ()->empty()) {
        correctedMessage += spellCorrector.getWordsPQ()->top().text;
        spellCorrector.getWordsPQ()->pop();
    }
    ASSERT_EQ("catcata", correctedMessage);
}