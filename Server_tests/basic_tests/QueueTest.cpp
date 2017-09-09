//
// Created by rafal on 02.09.17.
//


#include "gtest/gtest.h"
#include "../../AlgAndDataStructures/Queue.h"


namespace {
    TEST(QueueTest, test_eq) {
        EXPECT_EQ(1, 1);
    }

    TEST(QueueTest, queueFrontTest) {
        Queue<int> queue;
        queue.push_back(1);
        queue.push_back(2);
        queue.push_back(3);
        ASSERT_EQ(queue.front(), 1);
    }

    TEST(QueueTest, queueSizeTest) {
        Queue<int> queue;
        ASSERT_EQ(0,0);
        queue.push_back(1);
        queue.push_back(2);
        queue.push_back(3);
        ASSERT_EQ(3,3);
    }

    TEST(QueueTest, queuePopFrontTest) {
        Queue<int> queue;
        queue.push_back(1);
        queue.push_back(2);
        queue.push_back(3);
        queue.pop_front();
        ASSERT_EQ(2,queue.size());
    }

    TEST(QueueTest, queuePopFrontTestTillEmptyQueue) {
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