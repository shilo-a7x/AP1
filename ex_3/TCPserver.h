#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class TCPServer
{
private:
    // private variables for initializing the socket and detecting errors.
    const int BUFFER_SIZE = 4096;
    int sockId;
    int queueLen = 5;
    struct sockaddr_in sin;
    int error = 0;

public:
    /*
    Constructor function.
    */
    TCPServer(in_addr_t ip, in_port_t port);

    /*
    Accept connection to client
    */
    int accept();

    /*
    Send a string to the client.
    */
    void send(string string, int socket);

    /*
    Recive a string from the client.
    */
    string recv(int socket);

    // close the server.
    void close();

    // check if there was an error along the way somewhere.
    int getError();
};
