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

        // if there was an error when starting the server the error flag will be turned on.
        if (server.getError())
        {
            throw runtime_error("failed to initialize socket\n");
        }

        // get the info from the client and reply.
        while (true)
        {
            int clientSocket = server.accept();
            // Receive the message from the socket.
            string msg = server.recv(clientSocket), k, DIS, coordinate;

            // make sure there was no problem with reciving the message from the client.
            if (server.getError())
            {
                throw runtime_error("failed to receive\n");
            }

            vector<double> vec;
            double num;
            int K;

            // get the input as a stream.
            istringstream ss(msg);

            // put all the coordinates in a vector.
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

                // the first string that isn't a number is the distance.
                DIS = coordinate;
                break;
            }

            // the k is the last thing in the stream (the client checks fot other problems).
            ss >> k;

            // mskes sure k is positive.
            K = abs(stoi(k));

            // normelize k if it's too large.
            if (K > classified.size())
            {
                K = classified.size();
            }

            // makes sure the vector size is right. if not then it's an error.
            if (vec.size() != classified[0].getCoordinates().size())
            {
                server.send("invalid input", clientSocket);
                continue;
            }

            // initialize KNN with the distance and the k.
            KNN knnClassifier(DIS, K);

            // if the string given as input is not a valid distance code return error to the user.
            if (knnClassifier.isDisError())
            {
                server.send("invalid input", clientSocket);
                continue;
            }

            // run KNN and put the output in label.
            string label = knnClassifier.lunchKNN(classified, vec);

            // Send the label back.
            server.send(label, clientSocket);

            // make sure there was no problem with sending the message to the client.
            if (server.getError())
            {
                throw runtime_error("failed to send\n");
            }
        }
    }

    // if there was a problem send an error massage and quit.
    catch (const exception &e)
    {
        cout << "unable to run the server\n" << e.what() << endl;
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