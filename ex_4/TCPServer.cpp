#include "TCPServer.h"
#include <stdexcept>

TCPServer::TCPServer(in_addr_t ip, in_port_t port) : sockId(socket(AF_INET, SOCK_STREAM, 0)), from() {

    // initialize the socket and check it.
    if (sockId < 0) {
        error = 1;
    }

    // initialize the data structure.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = ip;
    sin.sin_port = port;
    // bind the socket to the port and ip.
    if (bind(sockId, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        error = 1;
    }

    // listen and check for errors in listening.
    if (listen(sockId, this->queueLen) < 0) {
        error = 1;
    }
}

int TCPServer::accept() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizof(client_sin);
    int clientSock = ::accept(sockId, (struct sockaddr *)&client_sin, addr_len);
    if (clientSock < 0) {
        return -1;
    }
    clientNum++;
    return clientSock;
}

void TCPServer::close() {
    ::close(this->sockId);
}
int TCPServer::getError() {
    return error;
}

void TCPServer::disconnectClient() {
    clientNum--;
}

int TCPServer::getClientNum() {
    return clientNum;
}