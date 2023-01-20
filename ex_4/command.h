#include "DefaultIO.h"
#include "KnnData.h"

#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H

using namespace std;

template<class T>
class Command {
private:
    string description;
    DefaultIO *io;
    KnnData<T> *data;
public:
    string getDescription() {
        return string(description);
    }

    DefaultIO *getIO() {
        return io;
    }

    KnnData<T> *getData() const {
        return data;
    }

    virtual void execute() = 0;

    Command(string description, DefaultIO *io, KnnData<T> *data) :
            description(move(description)), io(io), data(data) {}
};

#endif 