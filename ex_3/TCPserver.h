#include <netinet/in.h>
#include <sys/socket.h>

using namespace std;

class TCPServer {
private:
    const int BUFFER_SIZE = 4096;
    int sockId;
    int queueLen = 5;
    struct sockaddr_in from;
    int clientSock = 0;
    int error = 0;
    
public:
    TCPServer(in_addr_t ip, in_port_t port);

    void send(string string);

    string recv();

    void close();

    int getError (){
        return error;
    }
};
