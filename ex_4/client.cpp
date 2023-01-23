#include "SocketIO.h"
#include "TCPClient.h"
#include <arpa/inet.h>
#include <iostream>
#include <sstream>
#include <fstream>
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
        thread thread(receiving, &client);
    }
    catch (const exception &e)
    {
        cout << "Unable to run the client!\n"
             << e.what() << endl;
        return 0;
    }
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
    return 0;
}

void receiving(TCPClient *client)
{
    while (true)
    {
        const string &msg = client->recv();
        handleMessage(msg, client);
    }
}

void handleMessage(const string &msg, TCPClient *client)
{
    if (msg == "EXIT")
    {
        client->close();
        exit(0);
    }
    // Check if a message should be printed or saved to a file
    regex rgx("SAVE <((.|\\n)+)> TO <(.*)>");
    smatch matches;

    if (regex_search(msg, matches, rgx))
    {
        thread writer(writeFile, matches[3].str(), matches[1].str());
        writer.detach();
    }
    else
    {
        cout << msg << endl;
    }
}

// Write to a csv file
void writeFile(const string &path, const string &msg)
{
    ofstream fout(path);
    fout << msg;
}

// Check if a string is a directory of a file
bool isFile(const string &name)
{
    struct stat buffer;
    return ((stat(name.c_str(), &buffer) == 0) and (buffer.st_mode & S_IFREG));
}
