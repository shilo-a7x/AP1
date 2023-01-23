#include "Command.h"
#include <sstream>

#ifndef DOWNLOADCOMMAND_H
#define DOWNLOADCOMMAND_H

using namespace std;

class DownloadResultsCommand : public Command {
public:
    void execute() override;

    /**
     * A constructor function.
     */
    DownloadResultsCommand(DefaultIO *io, KnnData *data) : Command("download results", io, data) {}
};

#endif