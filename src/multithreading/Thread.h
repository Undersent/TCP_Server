//
// Created by rafal on 03.09.17.
//

#ifndef PROJECT_THREAD_H
#define PROJECT_THREAD_H


#include <zconf.h>

class Thread {
public:
    Thread() = default;
    virtual ~Thread();

    int start();
    int join();
    int detach();
    pthread_t self();

    virtual void* run() = 0;

private:
    pthread_t threadID{};
    int isRunning{};
    int isDetached{};
};


#endif //PROJECT_THREAD_H
