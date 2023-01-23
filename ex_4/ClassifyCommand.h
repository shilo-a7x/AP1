#include "Command.h"

#ifndef CLASSIFYCOMMAND_H
#define CLASSIFYCOMMAND_H

using namespace std;

class ClassifyCommand : public Command {
public:
    void execute() override;

    /**
     * A constructor function.
     */
    ClassifyCommand(DefaultIO *io, KnnData *data) : Command("classify data", io, data) {}
};

#endif