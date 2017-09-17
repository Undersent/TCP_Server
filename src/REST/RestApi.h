//
// Created by rafal on 15.09.17.
//

#ifndef PROJECT_RESTAPI_H
#define PROJECT_RESTAPI_H


#include "RestApi_I.h"

class RestApi : RestApi_I{
public:
    RestApi() = default;
    std::string get() override;

private:
    void post() override;
    void put() override;
    void deleteF() override;
};


#endif //PROJECT_RESTAPI_H
