//
// Created by rafal on 03.09.17.
//

#include "Queue.h"
template<typename T>
void Queue<T>::pop_front() {
    node* temp;
    temp = head;
    head= head->next;
    sizeQ--;
    delete temp;
    if(!sizeQ){
        head=tail= nullptr;
    }
}
template<typename T>
void Queue<T>::push_back(T data) {
    auto nodeT = new Queue::node;
    sizeQ++;
    nodeT->data=data;
    if(sizeQ == 1){
        tail = head = nodeT;
    }else{
        tail->next = nodeT;
        tail = nodeT;
    }
}

template<typename T>
T Queue<T>::front() const {
    return head->data;
}

template<typename T>
unsigned int Queue<T>::size() const {
    return sizeQ;
}
template<typename T>
Queue<T>::~Queue() {
    while(sizeQ){
        this->pop_front();
    }
}
