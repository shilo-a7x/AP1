#include "TCPServer.h"
#include "SocketIO.h"
#include "CLI.h"
#include "Command.h"
#include "UploadCommand.h"
#include "ChangeSetsCommand.h"
#include "ClassifyCommand.h"
#include "DisplayStringCommand.h"
#include "DownloadResultsCommand.h"
#include "KNN.h"
#include "KnnData.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <thread>

using namespace std;

void handleClient(int socket);

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
            thread t(handleClient, clientSocket);
            t.detach();
        }
    }

    // if there was a problem send an error massage and quit.
    catch (const exception &e) {
        cout << "unable to run the server\n" << e.what() << endl;
    }
    return 0;
}

void handleClient(int socket) {
    SocketIO io(socket);
    KNN knn("AUC", 5);
    KnnData knndata(&knn);
    vector<Command *> commands;
    UploadCommand c1(&io, &knndata);
    ChangeSetsCommand c2(&io, &knndata);
    ClassifyCommand c3(&io, &knndata);
    DisplayStringCommand c4(&io, &knndata);
    DownloadResultsCommand c5(&io, &knndata);
    commands.push_back(&c1);
    commands.push_back(&c2);
    commands.push_back(&c3);
    commands.push_back(&c4);
    commands.push_back(&c5);
    CLI cli(&io, commands);
    cli.run();
}
