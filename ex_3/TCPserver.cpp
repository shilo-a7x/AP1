#include "TCPserver.h"

TCPServer::TCPServer(in_addr_t ip, in_port_t port) : sockId(socket(AF_INET, SOCK_STREAM, 0)), from() {

    //Initialize the socket and check it
    if (sockId < 0) {
        error = 1;
    }
    //Initialize the data structure
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = ip;
    sin.sin_port = port;
    //Bind the socket to the port and ip
    if (bind(sockId, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        error = 1;
    }
}

void TCPServer::send(std::string string) {
    //Send the string through the socket
    int sent_bytes = ::send(this->clientSock, string.c_str(), strlen(string.c_str()), 0);
    if (sent_bytes < 0) {
        error = 1;
    }
}

string TCPServer::recv() {
    //Check if a client is connected
    if (this->clientSock == 0) {
        //Listen and accept the client
        if (listen(sockId, this->queueLen) < 0) {
            error = 1;
        }
        unsigned int addr_len = sizeof(this->from);
        this->clientSock = accept(sockId, (struct sockaddr *) &from, &addr_len);
        if (this->clientSock < 0) {
            error = 1;
        }
    }
    //Receive a message and save it in the buffer
    char buffer[Socket::buffer_size];
    int expected_data_len = Socket::buffer_size;
    int read_bytes = ::recv(this->clientSock, buffer, expected_data_len, 0);
    if (read_bytes < 0) {
        perror("error writing to sock");
    }
    //Create a string and return it
    std::string res(buffer);
    return res;
}

void TCPServer::close() {
    //Close the socket
    ::close(this->sockId);

}

int TCPServer::getError (){
        return error;
    }