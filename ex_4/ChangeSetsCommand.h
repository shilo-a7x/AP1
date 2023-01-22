#include "Command.h"
#include "Reader.h"
#include "Distance.h"

#ifndef CHANGEALGOSETTINGS_H
#define CHANGEALGOSETTINGS_H

using namespace std;

class ChangeSetsCommand : public Command
{
public:
    void execute() override;

    ChangeSetsCommand(DefaultIO *io, KnnData *data) : Command("algorithm settings", io, data) {}
};

#endif
