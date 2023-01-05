#include "Classifiable.h"
#include "KNN.h"
#include "Reader.h"
#include "TCPserver.h"
#include <iostream>
#include <sstream>

using namespace std;

// declaration.
bool is_number(const string &s);

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
        // use the reader and the data in order to build the vector DB.
        data = reader.readCSV(argv[1]);
        vector<Classifiable> classified = Classifiable::toVector(data, true);
        int port = atoi(argv[2]);
        TCPServer server(INADDR_ANY, htons(port));

        // if there was an error when ararting the server the error flag will be turned on.
        if (server.getError())
        {
            throw runtime_error("failed to initialize socket\n");
        }

        while (true)
        {
            // Receive the message from the socket.
            string msg = server.recv(), k, DIS, coordinate;
            vector<string> stringVec;
            vector<double> vec;
            double num;
            int K;
            istringstream ss(msg);
            while (true)
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
            K = stoi(k);
            if (K > classified.size())
            {
                K = classified.size();
            }
            if (vec.size() != classified[0].getCoordinates().size())
            {
                server.send("invalid input");
                continue;
            }
            KNN knnClassifier(DIS, K);
            string label = knnClassifier.lunchKNN(classified, vec);

            // Send the types back
            server.send(label);
        }
    }

    // if there was a problem send an error massage and quit.
    catch (const exception &e)
    {
        cout << "unable to start the server\n"
             << endl;
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