//
// Created by fstoeltie on 12/6/15.
//

#ifndef NETWORKING3_HTTPHANDLER_H
#define NETWORKING3_HTTPHANDLER_H

#include "PracticalSocket.h"
#include "RequestHandler.hpp"
#include "HTTP_Headers.hpp"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class HTTPHandler {
public:
    static void HandleHTTPRequests(TCPSocket *sock);
private:
    HTTPHandler();
    RequestHandler reqHandler;
    void sendData(HTTP_Headers & header, TCPSocket* sock);
    string datatype;
    bool resourceExists = false;
    int currentBufferSize;
};
#endif //NETWORKING3_HTTPHANDLER_H
