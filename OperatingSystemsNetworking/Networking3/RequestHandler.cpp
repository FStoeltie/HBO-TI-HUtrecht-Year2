//
// Created by fstoeltie on 12/6/15.
//

#include "RequestHandler.hpp"
using namespace std;
RequestHandler::RequestHandler()  {
    cout << "Created HTTP Data handler" << endl;
}
char* RequestHandler::checkIfResourceRequest(string GET)	{
    stringstream ss(GET);
    std::string t;
    ss >> t >> t;
    t.replace(0, 1, "");

    std::size_t pos = t.find(".");
    datatype = t.substr (pos+1);

    std::ifstream rFile(std::string("/home/fstoeltie/Desktop/Networking3/") + t, ios_base::binary | ios_base::ate);

    if(!rFile.is_open())	{
        cout << "Resource requested that coulden't be found!" << endl;
        currentBufferSize = 21;
        resExists |= 0x01;
        rFile.close();
        return "An Error has occured";
    }

    char *buffer = new char[rFile.tellg()];
    rFile.seekg(0);
    int posInArray = 0;
    char c;
    while(rFile.get(c))	{
        buffer[posInArray++] = c;
    }
    currentBufferSize = posInArray;
    rFile.close();

    resExists |= 0x00;
    return buffer;
}