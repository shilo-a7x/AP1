#include "DefaultIO.h"

#ifndef SOCKET_IO
#define SOCKET_IO

using namespace std;

class SocketIO : public DefaultIO {
private:
    static const int BUFFER_SIZE = 4096;
    int socket;

public:
    SocketIO(int socket);
    ~SocketIO();
    string read() override;
    void write(string string) override;
};

#endif