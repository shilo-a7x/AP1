#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <netinet/in.h>
#include <string>
#include <unistd.h>
#include <stdexcept>
#include <cstring>
#include <vector>

using namespace std;

/**
 * @brief this class is a TCP client
 * 
 */
class TCPClient {
private:
    static const int buffer_size = 4096;
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
     * @brief send a message to the server 
     * 
     * @param msg string message
     * @throws runtime_error if fails to send
     */
    void send(string msg);
    /**
     * @brief receives a message form server
     * 
     * @return string
     * @throws runtime_error if fails to receive
     */
    string recv();
    /**
     * @brief closes client socket
     * 
     */
    void close();
};

#endif