#include "DefaultIO.h"

#ifndef SOCKET_IO
#define SOCKET_IO

using namespace std;

class SocketIO : public DefaultIO {
public:
    void write(string string) override;

    string read() override;
};


#endif