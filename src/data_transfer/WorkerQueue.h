//
// Created by rafal on 03.09.17.
//

#ifndef PROJECT_WQUEUE_H
#define PROJECT_WQUEUE_H
#include <list>
#include <zconf.h>
#include <pthread.h>
#include "../../AlgAndDataStructures/Queue.h"
#include "../../AlgAndDataStructures/Queue.cpp"

template <typename T>
class WorkerQueue {
    //std::list<T> queue;
    Queue<T> queue;
    pthread_mutex_t mutex{};
    pthread_cond_t condv{};

public:
    WorkerQueue() {
        pthread_mutex_init(&mutex, NULL);
        pthread_cond_init(&condv, NULL);
    }
    ~WorkerQueue() {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&condv);
    }
    void add(T item) {
        pthread_mutex_lock(&mutex);
        queue.push_back(item);
        pthread_cond_signal(&condv);
        pthread_mutex_unlock(&mutex);
    }
    T remove() {
        pthread_mutex_lock(&mutex);
        while (queue.size() == 0) {
            pthread_cond_wait(&condv, &mutex);
        }
        T item = queue.front();
        queue.pop_front();
        pthread_mutex_unlock(&mutex);
        return item;
    }
    int size() {
        pthread_mutex_lock(&mutex);
        unsigned long size = queue.size();
        pthread_mutex_unlock(&mutex);
        return (int)size;
    }

};


#endif //PROJECT_WQUEUE_H
