#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <netinet/in.h>
#include <string>

using namespace std;

class TCPClient {
private:
    static const int buffer_size = 4096;
    int sock;
    struct sockaddr_in sin;
public:
    TCPClient(in_addr_t ip, in_port_t port);
    void send(string msg);
    string recv();
    void close();
};

#endif