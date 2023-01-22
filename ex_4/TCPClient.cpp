#include "TCPClient.h"

TCPClient::TCPClient(in_addr_t ip, in_port_t port)
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        throw runtime_error("error creating socket");
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = ip;
    sin.sin_port = port;
    if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        throw runtime_error("error connecting to server");
    }
}

void TCPClient::close()
{
    ::close(sock);
}

int TCPClient::getSocket()
{
    return sock;
}