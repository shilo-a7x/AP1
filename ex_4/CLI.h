#include <vector>
#include "Command.h"

#ifndef CLI_H
#define CLI_H

using namespace std;

class CLI
{
private:
    DefaultIO *io;
    vector<Command> commands;

    void printMenu();

public:
    CLI(DefaultIO *io, vector<Command> commands) : io(io), commands(move(commands)){}

    void run();
};

#endif