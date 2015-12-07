#include <iostream>

#include <thread>

#include "PracticalSocket.h"
#include "HTTPHandler.h"
int main(int argc, char *argv[]) {
	cout << "Launching Application\n";
  try {
    // Make a socket to listen for client connections.
    TCPServerSocket servSock(9091);
	cout << "server running: " << servSock.getLocalAddress().getAddress() << endl;
    for (;;)                      // Repeatedly accept connections
		thread(HTTPHandler::HandleHTTPRequests, servSock.accept()).detach();

  } catch (SocketException &e) {
    cerr << e.what() << endl;           // Report errors to the console

  }

  return 0;
}
