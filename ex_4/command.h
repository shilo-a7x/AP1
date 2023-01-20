#include "DefaultIO.h"
#include "KnnData.h"

#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H

using namespace std;

class Command
{
private:
    string description;
    DefaultIO *io;
    KnnData *data;

public:
    string getDescription()
    {
        return string(description);
    }

    DefaultIO *getIO()
    {
        return io;
    }

    KnnData *getData() const
    {
        return data;
    }

    virtual void execute() = 0;

    Command(string description, DefaultIO *io, KnnData *data) : description(move(description)), io(io), data(data) {}
};

#endif