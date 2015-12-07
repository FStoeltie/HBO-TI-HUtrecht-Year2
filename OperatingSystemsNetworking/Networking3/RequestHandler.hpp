//
// Created by fstoeltie on 12/6/15.
//

#ifndef NETWORKING3_RequestHandler_H
#define NETWORKING3_RequestHandler_H

#include <bits/stringfwd.h>
#include <iosfwd>
#include <sstream>
#include <fstream>
#include <iostream>


using namespace std;
class RequestHandler {
public:
    friend class HTTPHandler;
    char* checkIfResourceRequest(string GET);
    int resExists = 0x00;
private:
    RequestHandler();
    string datatype;
    int currentBufferSize = 0;
};

#endif //NETWORKING3_RequestHandler_H
