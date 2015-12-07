//
// Created by fstoeltie on 12/7/15.
//

#ifndef NETWORKING3_HTTP_HEADERS_HPP
#define NETWORKING3_HTTP_HEADERS_HPP

#include <string>
#include <stdint.h>
using namespace std;
struct HTTP_Headers   {
    HTTP_Headers(
    int bufferSize,
    string datatype, char* data,  uint8_t flagbits = 0x00) : flagbits(flagbits), bufferSize(bufferSize), datatype(datatype), data(data)  {
        
    }
    uint8_t flagbits = 0x00;
    int bufferSize;
    string datatype;
    char* data;
};


#endif //NETWORKING3_HTTP_HEADERS_HPP
