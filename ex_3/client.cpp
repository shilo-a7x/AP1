#include "TCPClient.h"
#include <iostream>
#include <arpa/inet.h>

using namespace std;

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
    } catch (const exception &e) {
        cout << "unable to start the server\n"
             << endl;
        return 0;
    }

   /*  while (true) {
        // Receive the message from the socket.
        string msg = server->recv(), k, DIS, coordinate;
        vector<string> stringVec;
        vector<double> vec;
        double num;
        int K;
        istringstream ss(msg);
        while(true) {
            ss >> coordinate;
            if (is_number(coordinate)) {
                // tures a string to a double.
                num = strtod(token.c_str(), 0);

                // add the number to the vector.
                vec.push_back(num);
                continue;
            }
            DIS = coordinate;
        }
        ss >> k;
        K = atoi(k);
        if (k > classified.size()) {
            k = classified.size();
        }
        if (v.size() != classified[0].getCoordinates().size()) {
            server->send("invalid input");
            continue;
        }
        KNN knnClassifier(DIS, K);
        string label = knnClassifier.lunchKNN(classified, vec);

        // Send the types back
        server->send(label);
    } */
    return 0;
}