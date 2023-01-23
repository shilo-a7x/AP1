#include "SocketIO.h"
#include "TCPClient.h"
#include <arpa/inet.h>
#include <iostream>
#include <sstream>
#include <thread>
#include "Reader.h"

using namespace std;

// declaration.
void handleMessage(const std::string &msg, TCPClient *client);
void receiving(TCPClient *client);
inline bool isFile(const std::string &name);

/*
The main function for lunching the client.
*/
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Needs 3 valid arguments to run the client!" << endl;
        return 0;
    }
    try
    {
        const char *ip = argv[1];
        int port = atoi(argv[2]);
        TCPClient client(inet_addr(ip), htons(port));
        SocketIO sio(client.getSocket());
        std::thread thread(receiving, &client);

        // receive input from user infinitely
        while (true)
        {
            string response;
            getline(cin, response);
            if (isFile(response))
            {
                response = Reader::readToString(response);
            }
            client.send(response);
        }
    }
    catch (const exception &e)
    {
        cout << "Unable to run the client!\n"
             << e.what() << endl;
        return 0;
    }
    return 0;
}

void receiving(TCPClient *client)
{
    while (true)
    {
        const std::string &msg = client->recv();
        handleMessage(msg, client);
    }
}

void handleMessage(const std::string &msg, TCPClient *client)
{
    if (msg == "exit")
    {
        client->close();
        exit(0);
    }
    // Check if a message should be printed or saved to a file
    std::regex rgx("SAVE <((.|\\n)+)> TO <(.*)>");
    std::smatch matches;

    if (std::regex_search(msg, matches, rgx))
    {
        utils::writeFile(matches[3].str(), matches[1].str());
    }
    else
    {
        std::cout << msg << std::endl;
    }
}

// Check if a string is a directory of a file
bool isFile(const std::string &name)
{
    struct stat buffer;
    return ((stat(name.c_str(), &buffer) == 0) and (buffer.st_mode & S_IFREG));
}
