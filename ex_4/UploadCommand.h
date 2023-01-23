#include "Command.h"
#include "Reader.h"

#ifndef UPLOADCOMMAND_H
#define UPLOADCOMMAND_H

using namespace std;

class UploadCommand : public Command {
public:
    void execute() override;

    /**
     * A constructor function.
     */
    UploadCommand(DefaultIO *io, KnnData *data) : Command("upload an unclassified csv data file", io, data) {}
};

#endif