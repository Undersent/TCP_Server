//
// Created by rafal on 02.09.17.
//


#include "gtest/gtest.h"
#include "../../AlgAndDataStructures/Queue.h"



namespace {

    class QueueTest : public ::testing::Test {
        public:
            Queue<int>* queue;
            QueueTest() = default;
            virtual ~QueueTest()  = default;

        void SetUp() override{
            queue = new Queue<int>;
        }

        void TearDown() override{
            delete queue;
        }
    };

    TEST_F(QueueTest, test_eq) {
        EXPECT_EQ(1, 1);
    }

    TEST_F(QueueTest, queueFrontTest) {
        int one{1}, two{2}, three{3};
        queue->push_back(one);
        queue->push_back(two);
        queue->push_back(three);
        ASSERT_EQ(queue->front(), 1);
    }

    TEST_F(QueueTest, queueSizeTest) {
        ASSERT_EQ(0,0);
        int one{1}, two{2}, three{3};
        queue->push_back(one);
        queue->push_back(two);
        queue->push_back(three);
        ASSERT_EQ(3,3);
    }

    TEST_F(QueueTest, queuePopFrontTest) {
        int one{1}, two{2}, three{3};
        queue->push_back(one);
        queue->push_back(two);
        queue->push_back(three);
        queue->pop_front();
        ASSERT_EQ(2,queue->size());
    }

    TEST_F(QueueTest, queuePopFrontTestTillEmptyQueue) {
        int one{1}, two{2}, three{3};
        queue->push_back(one);
        queue->push_back(two);
        queue->push_back(three);
        queue->pop_front();
        queue->pop_front();
        queue->pop_front();
        ASSERT_EQ(0,queue->size());
        queue->push_back(two);
        queue->push_back(three);
        ASSERT_EQ(2,queue->size());
    }


}