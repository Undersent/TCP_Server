//
// Created by rafal on 03.09.17.
//

#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H

template <typename T>
class Queue {
    struct Node
    {
        T data{};
        Node *next{};
    };
    //size pop_front push_back front
    Node* head = nullptr;
    Node* tail = nullptr;
    unsigned int sizeQ =0;

public:
    Queue() = default;
    ~Queue();

    unsigned int size() const;
    void pop_front()  ;
    void push_back(T& data);
    T front() const;
};

template<typename T>
void Queue<T>::pop_front() {
    Node* temp;
    temp = head;
    head= head->next;
    sizeQ--;
    delete temp;
    if(!sizeQ){
        head=tail= nullptr;
    }
}
template<typename T>
void Queue<T>::push_back(T& data) {
    auto nodeT = new Queue::Node;
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
#endif //PROJECT_QUEUE_H
