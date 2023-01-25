#include "Command.h"
#include <vector>

#ifndef CLI_H
#define CLI_H

using namespace std;

class CLI {
private:
    DefaultIO *io;
    vector<Command *> commands;

    void printMenu(string);

public:
    CLI(DefaultIO *io, vector<Command *> commands) : io(io), commands(commands) {}

    void run();
};

#endif