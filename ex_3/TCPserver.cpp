#include "TCPserver.h"


TCPServer::TCPServer(in_addr_t ip, in_port_t port) : sockId(socket(AF_INET, SOCK_STREAM, 0))
{

    // initialize the socket and check it.
    if (sockId < 0)
    {
        error = 1;
    }

    // initialize the data structure.
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = ip;
    sin.sin_port = port;

    // bind the socket to the port and ip.
    if (bind(sockId, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        error = 1;
    }
    // listen the client. check for errors along the way.
    if (listen(sockId, this->queueLen) < 0)
    {
        error = 1;
    }
}

int TCPServer::accept() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int clientSock = ::accept(sockId, (struct sockaddr *)&client_sin, &addr_len);
    if (clientSock < 0)
    {
        error = 1;
    }
    return clientSock;
}

void TCPServer::send(std::string string, int socket)
{

    // send the string through the socket.
    int sent_bytes = ::send(socket, string.c_str(), strlen(string.c_str()), 0);
    if (sent_bytes < 0)
    {
        error = 1;
    }
}

string TCPServer::recv(int socket)
{
    // receive a message and save it in the buffer.
    char buffer[BUFFER_SIZE];
    int expected_data_len = BUFFER_SIZE;
    int read_bytes = ::recv(socket, buffer, expected_data_len, 0);
    if (read_bytes < 0)
    {
        error = 1;
    }

    // create a string and return it.
    std::string res(buffer, strlen(buffer));
    return res;
}

void TCPServer::close()
{
    ::close(this->sockId);
}

int TCPServer::getError()
{
    return error;
}