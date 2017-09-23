//
// Created by rafal on 03.09.17.
//

#ifndef PROJECT_WORKITEM_H
#define PROJECT_WORKITEM_H
#include "string"
#include "../network/TCPStreamData.h"

class WorkItem
{
    TCPStreamData* m_stream;

public:
    explicit WorkItem(TCPStreamData* stream) : m_stream(stream) {}
    ~WorkItem() { delete m_stream; }

    TCPStreamData* getStream() { return m_stream; }
};
#endif //PROJECT_WORKITEM_H