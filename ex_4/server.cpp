#include "Classifiable.h"
#include "KNN.h"
#include "Reader.h"
#include "TCPServer.h"
#include <iostream>
#include <sstream>
#include <thread>

using namespace std;

// declaration.
bool is_number(const string &s);

/*
The main function for lunching the server.
*/
int main(int argc, char *argv[]) {
    // making sure the user sent a arguments.
    if (argc != 2) {
        cout << "Needs 3 valid arguments to run the server!" << endl;
        return 0;
    }

    // if there's an exeption while initializing the server don't crash, just send an error massage and quit.
    try {
        // use the reader and the data in order to build the vector DB.
        int port = atoi(argv[1]);
        TCPServer server(INADDR_ANY, htons(port));

        // if there was an error when starting the server the error flag will be turned on.
        if (server.getError()) {
            throw runtime_error("failed to initialize socket\n");
        }

        // get the info from the client and reply.
        while (true) {
            int clientSocket = server.accept();
        }
    }

    // if there was a problem send an error massage and quit.
    catch (const exception &e) {
        cout << "unable to run the server\n"
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
