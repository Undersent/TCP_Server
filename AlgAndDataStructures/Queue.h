//
// Created by rafal on 03.09.17.
//

#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H

template <typename T>
class Queue {
    struct node
    {
        T data;
        node *next;
    };
    //size pop_front push_back front
    node* head = nullptr;
    node* tail = nullptr;
    unsigned int sizeQ =0;

public:
    Queue() = default;
    ~Queue();

    unsigned int size() const;
    void pop_front();
    void push_back(T data);
    T front() const;


};


#endif //PROJECT_QUEUE_H
