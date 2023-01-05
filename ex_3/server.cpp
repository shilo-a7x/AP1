#include <iostream>
#include "TCPserver.h"
#include "KNN.h"
#include "Classifiable.h"
#include "Reader.h"

using namespace std;

/*
The main function for lunching the server.
*/
int main(int argc, char *argv[])
{
    // making sure the user sent a arguments.
    if (argc != 3)
    {
        cout << "Needs 3 valid arguments to run the server!" << endl;
        return 0;
    }
    Reader reader;
    vector<vector<string>> data;

    // if there's an exeption while initializing the server don't crash, just send an error massage and quit.
    try
    {
        // use the reader in order
        data = reader.readCSV(argv[1]);
        vector<Classifiable> classified = Classifiable::toVector(data, true);
        int port = atoi(argv[2]);
        server = new TCPServer(INADDR_ANY, htons(port));
        if (server->error)
        {
            throw runtime_error("failed to initialize socket\n");
        }
    }

    // if there was a problem send an error massage and quit.
    catch (const exception &e)
    {
        cout << "unable to start the server\n"
             << endl;
        return 0;
    }

    while (true)
    {
        // Receive the message from the socket.
        string msg = server->recv(), k, DIS, coordinate;
        vector<string> stringVec;
        vector<double> vec;
        double num;
        int K;
        istringstream ss(msg);
        whlie(true)
        {
            ss >> coordinate;
            if (is_number(coordinate))
            {
                // tures a string to a double.
                num = strtod(coordinate.c_str(), 0);

                // add the number to the vector.
                vec.push_back(num);
                continue;
            }
            DIS = coordinate;
            break;
        }
        ss >> k;
        K = atoi(k);
        if (k > classified.size())
        {
            k = classified.size();
        }
        if (v.size() != classified[0].getCoordinates().size())
        {
            server->send("invalid input");
            continue;
        }
        KNN knnClassifier(DIS, K);
        string label = knnClassifier.lunchKNN(classified, vec);

        // Send the types back
        server->send(label);
    }
    return 0;
}