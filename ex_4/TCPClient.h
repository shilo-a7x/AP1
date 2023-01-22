#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <cstring>
#include <netinet/in.h>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

/**
 * @brief this class is a TCP client
 *
 */
class TCPClient
{
private:
    int sock;
    struct sockaddr_in sin;

public:
    /**
     * @brief Construct a new TCPClient object
     *
     * @param ip an IPv4 address
     * @param port socket port number
     * @throws runtime_error if fails to create socket or to connect
     */
    TCPClient(in_addr_t ip, in_port_t port);

    /**
     * @brief closes client socket
     *
     */
    void close();

    int getSocket();
}
