//
// Created by rafal on 02.09.17.
//

#include "SampleTest.h"
#include "gtest/gtest.h"
#include "../../AlgAndDataStructures/RSA.h"
#include "../../AlgAndDataStructures/RSA.cpp"
#include "../../AlgAndDataStructures/Queue.h"
#include "../../AlgAndDataStructures/Queue.cpp"

namespace {
    TEST(SampleTest, test_eq) {
        EXPECT_EQ(1, 1);
    }

    TEST(SampleTest, testRSA) {
        RSA rsa;
        EXPECT_EQ(5, rsa.get5());
    }
    TEST(SampleTest, queueFrontTest) {
        Queue<int> queue;
        queue.push_back(1);
        queue.push_back(2);
        queue.push_back(3);
        ASSERT_EQ(queue.front(), 1);
    }

    TEST(SampleTest, queueSizeTest) {
        Queue<int> queue;
        ASSERT_EQ(0,0);
        queue.push_back(1);
        queue.push_back(2);
        queue.push_back(3);
        ASSERT_EQ(3,3);
    }

    TEST(SampleTest, queuePopFrontTest) {
        Queue<int> queue;
        queue.push_back(1);
        queue.push_back(2);
        queue.push_back(3);
        queue.pop_front();
        ASSERT_EQ(2,queue.size());
    }

    TEST(SampleTest, queuePopFrontTestTillEmptyQueue) {
        Queue<int> queue;
        queue.push_back(1);
        queue.push_back(2);
        queue.push_back(3);
        queue.pop_front();
        queue.pop_front();
        queue.pop_front();
        ASSERT_EQ(0,queue.size());
        queue.push_back(2);
        queue.push_back(3);
        ASSERT_EQ(2,queue.size());
    }


}