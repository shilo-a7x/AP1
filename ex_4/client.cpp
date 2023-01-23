#include "SocketIO.h"
#include "TCPClient.h"
#include <arpa/inet.h>
#include <iostream>
#include <sstream>

using namespace std;

// declaration.
bool is_number(const string &s);

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
        while (true) {
            cout << sio.read() << endl;
            string choice;
            getline(cin, choice);
            if (input.empty()) {
                cout << "invalid input" << endl;
                continue;
            }
            sio.write(choice);

            istringstream iss(input);
            string msg = "";
            string token;
            // expected input: vector<double>  string_metric int_k
            bool isValid = false;
            while (iss >> token) {
                if (is_number(token)) {
                    msg += token;
                    msg.append(" ");
                    isValid = true;
                } else {
                    // first non-number string
                    msg += token;
                    msg.append(" ");
                    break;
                }
            }
            isValid = false;
            if (iss >> token && is_number(token)) {
                msg += token;
                msg.append("\n");
                isValid = true;
            }
            if (!isValid) {
                cout << "invalid input" << endl;
                continue;
            }
            client.send(msg);
            cout << client.recv() << endl;
        }
    } catch (const exception &e) {
        cout << "Unable to run the client!\n"
             << e.what() << endl;
        return 0;
    }
    return 0;
}

/*
return true if the string given represents a double and false otherwise.
*/
bool is_number(const string &s) {
    long double ld;

    // return true if the string given to the buffer is a long double and false if not.
    return ((istringstream(s) >> ld >> ws).eof());
}
