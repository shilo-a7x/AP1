#include "TCPClient.h"
#include <unistd.h>
#include <stdexcept>
#include <cstring>

void TCPClient::TCPClient(in_addr_t ip, in_port_t port) {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        throw runtime_error("error creating socket");
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip);
    sin.sin_port = htons(port);
    if (connect(sock, (struct sockaddr*) &sin, sizeof(sin)) < 0) {
        throw runtime_error("error connecting to server");
    }
}

void TCPClient::send(string msg) {
    int sent_bytes = ::send(sock, msg.c_str(), strlen(msg.c_str()), 0);
    if (sent_bytes < 0) {
        throw runtime_error("error sending to server");
    }
}

string TCPClient::recv() {
    char buffer[buffer_size];
    memset(buffer, 0, sizeof(buffer));
    int expected_data_len = sizeof(buffer);
    int read_bytes = ::recv(sock, buffer, expected_data_len, 0);
    if (read_bytes < 0) {
        throw runtime_error("error receiving from server");
    }
    string msg(buffer, strlen(buffer));
    return msg;
}

void TCPCliet::close() {
    ::close(sock);
}