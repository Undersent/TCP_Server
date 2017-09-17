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
        int one{1}, two{2}, three{3};
        queue.push_back(one);
        queue.push_back(two);
        queue.push_back(three);
        ASSERT_EQ(queue.front(), 1);
    }

    TEST(QueueTest, queueSizeTest) {
        Queue<int> queue;
        ASSERT_EQ(0,0);
        int one{1}, two{2}, three{3};
        queue.push_back(one);
        queue.push_back(two);
        queue.push_back(three);
        ASSERT_EQ(3,3);
    }

    TEST(QueueTest, queuePopFrontTest) {
        Queue<int> queue;
        int one{1}, two{2}, three{3};
        queue.push_back(one);
        queue.push_back(two);
        queue.push_back(three);
        queue.pop_front();
        ASSERT_EQ(2,queue.size());
    }

    TEST(QueueTest, queuePopFrontTestTillEmptyQueue) {
        Queue<int> queue;
        int one{1}, two{2}, three{3};
        queue.push_back(one);
        queue.push_back(two);
        queue.push_back(three);
        queue.pop_front();
        queue.pop_front();
        queue.pop_front();
        ASSERT_EQ(0,queue.size());
        queue.push_back(two);
        queue.push_back(three);
        ASSERT_EQ(2,queue.size());
    }


}