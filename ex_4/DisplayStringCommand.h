#include "Command.h"

#ifndef DISPLAYSTRINGCOMMAND_H
#define DISPLAYSTRINGCOMMAND_H

using namespace std;

class DisplayStringCommand : public Command {
public:
    void execute() override;

    /**
     * A constructor function.
     */
    DisplayStringCommand(DefaultIO *io, KnnData *data) : Command("display results", io, data) {}
};

#endif