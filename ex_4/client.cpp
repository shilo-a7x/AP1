#include "SocketIO.h"
#include "TCPClient.h"
#include <arpa/inet.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <thread>
#include <regex>
#include <stdexcept>
#include <sys/stat.h>
#include "Reader.h"

using namespace std;

// declaration.
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

        // receive input from user infinitely
        while (true)
        {
            string menu = sio.read();
            cout << menu << endl;
            string choice, input, input1, stringFile, msg;
            int response, i;
            getline(cin, choice);
            try
            {
                if (choice.empty())
                {
                    throw runtime_error("error");
                }
                response = stoi(choice);
            }
            catch (const exception &e)
            {
                sio.write("ERROR");
                cout << sio.read() << endl;
                sio.write("OK");
                continue;
            }
            sio.write(choice);
            switch (response)
            {
            case 1:
            {
                for (i = 0; i < 2; i++)
                {
                    cout << sio.read() << endl;
                    getline(cin, input);
                    if (!isFile(input))
                    {
                        sio.write("");
                        cout << sio.read() << endl;
                        break;
                    }
                    try
                    {
                        sio.write(Reader::readToString(input));
                    }
                    catch (const exception &e)
                    {
                        sio.write("");
                        cout << "failed to upload file\n"
                             << e.what() << endl;
                        break;
                    }
                }
            }
            break;
            case 2:
            {
                cout << sio.read() << endl;
                getline(cin, input);
                sio.write(input);
                input1 = sio.read();
                if (input1 == "")
                {
                    break;
                }
                cout << sio.read() << endl;
            }
            break;
            case 3:
            {
                cout << sio.read() << endl;
            }
            break;
            case 4:
            {
                cout << sio.read() << endl;
                getline(cin, input);
                sio.write(input);
            }
            break;
            case 5:
            {
                cout << sio.read() << endl;
                sio.write("ok");
                stringFile = sio.read();
                if (stringFile == "")
                {
                    break;
                }
                getline(cin, input);
                if (!isFile(input))
                {
                    sio.write("");
                    cout << sio.read() << endl;
                    break;
                }
                ofstream fout(input);
                fout << stringFile;
            }
            break;
            case 8:
            {
                client.close();
                exit(0);
            }
            break;
            default:
            {
                sio.write("ERROR");
                msg = sio.read();
                cout << msg << endl;
                sio.write("OK");
                cout << "send ok" << endl;
                continue;
            }
            }
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

// Check if a string is a directory of a file
bool isFile(const string &name)
{
    struct stat buffer;
    return ((stat(name.c_str(), &buffer) == 0) and (buffer.st_mode & S_IFREG));
}
