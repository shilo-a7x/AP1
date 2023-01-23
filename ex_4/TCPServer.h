#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "SocketIO.h"
#include <cstring>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

class TCPServer {
private:
    // private variables for initializing the socket and detecting errors.
    int sockId;
    int queueLen = 5;
    int error = 0;

public:
    /*
    Constructor function.
    */
    TCPServer(in_addr_t ip, in_port_t port);

    /*
    Accept a connection with a client
    */
    int accept();

    // close the server.
    void close();

    // check if there was an error along the way somewhere.
    int getError();

};

#endif