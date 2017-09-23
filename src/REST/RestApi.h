//
// Created by rafal on 15.09.17.
//

#ifndef PROJECT_RESTAPI_H
#define PROJECT_RESTAPI_H


#include "RestApi_I.h"

class RestApi :public RestApi_I{
private:
    std::string _msg;
    int _socket;

public:
    RestApi() = default;
    ~RestApi() = default;
    std::string get() override;
    bool prepareSocketConnection(const std::string& ipAdress,const int port) override;
    void setMsg(const std::string &msg) override;
private:

    void post() override;
    void put() override;
    void deleteF() override;

};


#endif //PROJECT_RESTAPI_H
