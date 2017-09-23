//
// Created by rafal on 23.09.17.
//

#include <gtest/gtest.h>
#include <thread>
#include "../../src/data_transfer/WorkerQueue.h"
#include "../../src/multithreading/Thread.h"

#include <pthread.h>

class WorkerQueueTest : public ::testing::Test {
public:
    WorkerQueue<int> *workerQueue;
    pthread_t threadID{};
    pthread_t threadID2{};
    int result;
    int result2;

    WorkerQueueTest(){

    }
    ~WorkerQueueTest() override  = default;

    static void* runAddThread1(void *arg){
        for(int i{}; i<1000; i++) {
            ((WorkerQueue<int> *) arg)->add(1);
        }
    };
    static void* runAddThread2(void *arg){
        for(int i{}; i<1000; i++) {
            ((WorkerQueue<int> *) arg)->add(2);
        }
    };

    static void* runDeleteThread(void * arg){
        for(int i{}; i<1000; i++) {
            ((WorkerQueue<int> *) arg)->remove();
        }
    }

    void SetUp() override{
        workerQueue = new WorkerQueue<int>;
        result = pthread_create(&threadID, nullptr, runAddThread1, workerQueue);
        result2 = pthread_create(&threadID2, nullptr, runAddThread2, workerQueue);
    }

    void TearDown() override{
        delete workerQueue;
    }
};


TEST_F(WorkerQueueTest, isAddingThreadSafe){
    pthread_detach(threadID);
    pthread_detach(threadID2);
    std::this_thread::sleep_for (std::chrono::microseconds(1000)); //troche bieda
    ASSERT_EQ(workerQueue->size(),2000);
}

TEST_F(WorkerQueueTest, isDeletingThreadSafe){
    pthread_detach(threadID);
    pthread_detach(threadID2);
    std::this_thread::sleep_for (std::chrono::microseconds(1000)); //troche bieda
    pthread_create(&threadID, nullptr, runDeleteThread, workerQueue);
    std::this_thread::sleep_for (std::chrono::microseconds(1000)); //troche bieda
    ASSERT_EQ(workerQueue->size(),1000);

}