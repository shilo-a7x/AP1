#include "SocketIO.h"
#include <cstring>
#include <stdexcept>
#include <sys/socket.h>
#include <unistd.h>

SocketIO::SocketIO(int socket) : socket(socket) {}

SocketIO::~SocketIO() {
    close(socket);
}

string SocketIO::read() {
    char buffer[BUFFER_SIZE];
    int read_bytes;
    string msg;
    do {
        memset(buffer, 0, BUFFER_SIZE);
        read_bytes = recv(socket, buffer, BUFFER_SIZE, 0);
        if (read_bytes < 0) {
            throw runtime_error("Failed to recieve messege");
        }
        msg += buffer;
    } while (read_bytes >= BUFFER_SIZE);
    return msg;
}

void SocketIO::write(string msg) {
    int sent_bytes = send(socket, msg.c_str(), strlen(msg.c_str()), 0);
    if (sent_bytes < 0) {
        throw runtime_error("Failed to send message");
    }
}