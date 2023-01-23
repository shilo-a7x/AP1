#include "DefaultIO.h"
#include "KnnData.h"

#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H

using namespace std;

class Command {
private:
    string description;
    DefaultIO *io;
    KnnData *data;

public:
    /**
     * A getter fot the commands menu string.
     */
    string getDescription() {
        return string(description);
    }

    /**
     * A getter for the commands io.
     */
    DefaultIO *getIO() {
        return io;
    }

    /**
     * A getter for the commands data.
     */
    KnnData *getData() const {
        return data;
    }

    /**
     * The command that each inheriting class needs to impement.
     */
    virtual void execute() = 0;

    /**
     * A constructor that works for each command.
     * Initializes the description on the spot.
     */
    Command(string description, DefaultIO *io, KnnData *data) : description(description), io(io), data(data) {}

    virtual ~Command() = default;
};

#endif
