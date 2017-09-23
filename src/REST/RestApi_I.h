//
// Created by rafal on 15.09.17.
//

#ifndef PROJECT_RESTAPI_I_H
#define PROJECT_RESTAPI_I_H

#endif //PROJECT_RESTAPI_I_H

#include "string"
class RestApi_I {
public:
    virtual std::string get() = 0;
    virtual void post() = 0;
    virtual void put() = 0;
    virtual void deleteF() = 0;
    //troche na sile zrobione. W celu mockowania obiektu
    virtual bool prepareSocketConnection(const std::string& ipAdress,const int port) = 0;
    virtual void setMsg(const std::string &msg) = 0;
};
