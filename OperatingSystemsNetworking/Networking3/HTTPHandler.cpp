//
// Created by fstoeltie on 12/6/15.
//

#include "HTTPHandler.h"
using namespace std;

//maak je eigen getline
//deze beschouwt  LF en ook CR+LF en ook CR  als einde-regel markering
//dit is nodig om requests die afkomstig zijn van diverse OS aan te kunnen.
istream & getline(istream & in, string & out) {
    char c;
    out.clear();

    while(in.get(c).good()) {
        if(c == '\r') {
            c = in.peek();
            if(in.good() && c == '\n' ) {
                in.ignore();
            }
            break;
        }
        if(c == '\n') break;
        out.append(1,c);
    }
    return in;
}
HTTPHandler::HTTPHandler()   {

}
void HTTPHandler::sendData(HTTP_Headers & header, TCPSocket* sock) {
    string http_query;
    if (header.flagbits & 0x01 == 0x01) // failed
        http_query = "HTTP/1.1 404 Not Found\nContent-Length: " + to_string(header.bufferSize) + "\nContent-Type: text/html" + "\n\n";
    else
        http_query = "HTTP/1.1 200 OK\nContent-Length: " + to_string(header.bufferSize) + "\nContent-Type: " + header.datatype + "\n\n";
    cout << "\nStart of HTTP_Query\n\n" << http_query << "\n\n";
    sock->getStream() << http_query;
    sock->getStream().flush();
    sock->send(header.data, header.bufferSize);
    sock->cleanUp();
}
void HTTPHandler::HandleHTTPRequests(TCPSocket *sock)  {
    HTTPHandler curHTTPHandler;
    string regel;
    iostream& stream = sock->getStream();
    cout << "Started new thread object and reading HTTP stream" << endl;
    while(getline(stream, regel)){
        cout << regel << endl;
        char* temp;
        if(regel.compare(0, 3, "GET") == 0)	{
            temp = curHTTPHandler.reqHandler.checkIfResourceRequest(regel);
        }
        if(regel.empty() ) {
            HTTP_Headers curData( curHTTPHandler.reqHandler.currentBufferSize, curHTTPHandler.datatype , temp, curHTTPHandler.reqHandler.resExists);
            curHTTPHandler.sendData(curData, sock);
        }
    }
    delete sock;
}