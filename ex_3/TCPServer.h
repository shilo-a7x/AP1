#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <cstring>

using namespace std;

class TCPServer
{
private:

    // private variables for initializing the socket and detecting errors.
    const int BUFFER_SIZE = 4096;
    int sockId;
    int queueLen = 5;
    struct sockaddr_in from;
    int clientSock = 0;
    int error = 0;

public:
    /*
    Constructor function.
    */
    TCPServer(in_addr_t ip, in_port_t port);

    /*
    Send a string to the client.
    */
    void send(string string);

    /*
    Recive a string from the client.
    */
    string recv();

    // close the server.
    void close();

    // check if there was an error along the way somewhere.
    int getError();
};
