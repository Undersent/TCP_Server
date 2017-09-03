//
// Created by rafal on 02.09.17.
//

#include "SampleTest.h"
#include "gtest/gtest.h"
#include "../../AlgAndDataStructures/RSA.h"


TEST(SampleTest, test_eq){
    EXPECT_EQ(1,1);
}

TEST(SampleTest, testRSA){
    EXPECT_EQ(5, RSA::get5());
}


