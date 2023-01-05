#include "TCPClient.h"
#include <iostream>
#include <sstream>
#include <arpa/inet.h>

using namespace std;

// declaration.
bool is_number(const string &s);

/*
The main function for lunching the server.
*/
int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Needs 3 valid arguments to run the server!" << endl;
        return 0;
    }
    try {
        const char* ip = argv[1];
        int port = atoi(argv[2]);
        TCPClient client(inet_addr(ip), htons(port));
        while (true) {
            string input;
            getline(cin, input);
            if (!input.compare("-1")) {
                client.close();
                return 0;
            }
            istringstream iss(input);
            string msg;
            string token;
            while (iss >> token) {
                if (is_number(token)) {
                    msg += token;
                } else {
                    msg += token;
                    break;
                }                
            }
            iss >> token;
            if (is int) { ///////
                msg+= token
            } else {
                invalid 
                continue;
            } 

        }
    } catch (const exception &e) {
        cout << "Unable to connect the server!\n" << endl;
        return 0;
    }
    return 0;
}

/*
return true if the string given represents a double and false otherwise.
*/
bool is_number(const string &s)
{
    long double ld;

    // return true if the string given to the buffer is a long double and false if not.
    return ((istringstream(s) >> ld >> ws).eof());
}