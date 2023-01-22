#include "TCPServer.h"

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

void TCPServer::send(std::string string) {
    // send the string through the socket.
    int sent_bytes = ::send(this->clientSock, string.c_str(), strlen(string.c_str()), 0);
    if (sent_bytes < 0) {
        error = 1;
    }
}

int TCPServer::accept() {
    
}

string TCPServer::recv() {
    // check if a client is connected.
    if (this->clientSock == 0) {
        unsigned int addr_len = sizeof(this->from);
        this->clientSock = accept(sockId, (struct sockaddr *)&from, &addr_len);
        if (this->clientSock < 0) {
            error = 1;
        }
    }

    // receive a message and save it in the buffer.
    char buffer[BUFFER_SIZE];
    int expected_data_len = BUFFER_SIZE;
    int read_bytes = ::recv(this->clientSock, buffer, expected_data_len, 0);
    if (read_bytes < 0) {
        error = 1;
    }

    // if the client left reset the clientSock.
    if (read_bytes == 0) {
        clientSock = 0;
        return recv();
    }

    // create a string and return it.
    string res(buffer, strlen(buffer));
    return res;
}
void TCPServer::close() {
    ::close(this->sockId);
}
int TCPServer::getError() {
    return error;
}