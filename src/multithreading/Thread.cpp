//
// Created by rafal on 03.09.17.
//

#include <pthread.h>
#include "Thread.h"

Thread::~Thread() {
    if(isRunning && !isDetached){
        pthread_detach(threadID);
    }
    if( isRunning){
        pthread_cancel(threadID);
    }
}

static void* runThread(void* arg){
    return ((Thread*)arg)->run();
}

int Thread::start() {
    int result = pthread_create(&threadID, nullptr, runThread, this);
    if (!result) {
        isRunning = 1;
    }
    return result;
}

int Thread::join() {
    int result = -1;
    if (isRunning) {
        result = pthread_join(threadID, nullptr);
        if(!result) {
            isDetached = 1;
        }
    }
    return result;
}

int Thread::detach() {
    int result = -1;
    if(isRunning && !isDetached) {
        result = pthread_detach(threadID);
        if (!result) {
            isDetached = 1;
        }
    }
    return result;
}

pthread_t Thread::self() {
    return threadID;
}
