#include "Reader.h"
#include "SocketIO.h"
#include "TCPClient.h"
#include <arpa/inet.h>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <sys/stat.h>
#include <thread>

using namespace std;

// declaration.
inline bool isFile(const std::string &name);
string clientRecieve(SocketIO &sio);
int clientSend(string ans, SocketIO &sio);
void uploadData(SocketIO &sio);
// void downloadData(SocketIO &sio);

/*
The main function for lunching the client.
*/
int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Needs 3 valid arguments to run the client!" << endl;
        return 0;
    }
    try {
        const char *ip = argv[1];
        int port = atoi(argv[2]);
        TCPClient client(inet_addr(ip), htons(port));
        SocketIO sio(client.getSocket());

        // receive input from user infinitely
        while (true)
        {
            string answer = clientRecieve(sio);
            if (clientSend(answer, sio))
            {
                client.close();
                exit(0);
            }
        }
    } catch (const exception &e) {
        cout << "Unable to run the client!\n"
             << e.what() << endl;
        return 0;
    }
    return 0;
}

// Check if a string is a directory of a file
bool isFile(const string &name) {
    struct stat buffer;
    return ((stat(name.c_str(), &buffer) == 0) and (buffer.st_mode & S_IFREG));
}

string clientRecieve(SocketIO &sio)
{
    string s = sio.read();
    if (s.find("EXIT") != string::npos)
    {
        return s;
    }
    cout << s << endl;
    if (s.find("invalid value") != string::npos || s.find("please upload data") != string::npos || s.find("classifying data complete") != string::npos || s.find("please classify the data") != string::npos)
    {
        sio.write("space");
    }
    return s;
}

int clientSend(string s, SocketIO &sio)
{
    if (s.find("EXIT") != string::npos)
    {
        return 1;
    }
    if (s.find("invalid value") != string::npos || s.find("please upload data") != string::npos || s.find("classifying data complete") != string::npos || s.find("please classify the data") != string::npos)
    {
        return 0;
    }
    string input, path;
    getline(cin, input);
    if (input.empty())
    {
        input = "ENTER";
    }
    sio.write(input);
    if (input == "1")
    {
        uploadData(sio);
        return 0;
    }
    if (input == "5")
    {
        // downloadData();
        // return 0;
        cout << "got 5" << endl;
        input = "ENTER";
    }
    return 0;
}

void uploadData(SocketIO &sio)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        string input, path;
        cout << sio.read() << endl;
        getline(cin, path);
        if (!isFile(path) || path.empty())
        {
            cout << "invalid input" << endl;
            sio.write("ERROR");
            return;
        }
        try
        {
            sio.write(Reader::readToString(path));
        }
        catch (const exception &e)
        {
            cout << "failed to upload file\n"
                 << e.what() << endl;
        }
        cout << sio.read() << endl;
        sio.write("OK");
    }
}

// void downloadData(SocketIO &sio)

// switch (response)
// {
// case 1:
// {
//     for (i = 0; i < 2; i++)
//     {
// cout << sio.read() << endl;
// getline(cin, input);
// if (!isFile(input))
// {
//     sio.write("");
//     cout << sio.read() << endl;
//     break;
// }
// try
// {
//     sio.write(Reader::readToString(input));
// }
// catch (const exception &e)
// {
//     sio.write("");
//     cout << "failed to upload file\n"
//          << e.what() << endl;
//     break;
// }
//     }
// }
// break;
// case 2:
// {
//     cout << sio.read() << endl;
//     input = "";
//     getline(cin, input);
//     sio.write(input);
//     if (choice.empty())
//     {
//         break;
//     }
//     string input1 = sio.read();
//     if (input1 == "ok")
//     {
//         break;
//     }
//     cout << sio.read() << endl;
// }
// break;
// case 3:
// {
//     cout << sio.read() << endl;
// }
// break;
// case 4:
// {
//     cout << sio.read() << endl;
//     getline(cin, input);
//     sio.write(input);
// }
// break;
// case 5:
// {
//     cout << sio.read() << endl;
//     sio.write("ok");
//     input = sio.read();
//     if (input == "")
//     {
//         break;
//     }
//     getline(cin, input);
//     if (!isFile(input))
//     {
//         sio.write("");
//         cout << sio.read() << endl;
//         break;
//     }
//     ofstream fout(input);
//     fout << input;
// }
// break;
// case 8:
// {
//     client.close();
//     exit(0);
// }
// break;
// default:
// {
//     sio.write("ERROR");
//     cout << sio.read() << endl;
//     sio.write("OK");
//     continue;
// }
// }