/*
header for the ChangeSetsCommand class.
*/

#include "Command.h"
#include "Distance.h"
#include "Reader.h"

#ifndef CHANGEALGOSETTINGS_H
#define CHANGEALGOSETTINGS_H

using namespace std;

class ChangeSetsCommand : public Command
{
public:
    void execute() override;

    /**
     * A constructor function.
     */
    ChangeSetsCommand(DefaultIO *io, KnnData *data) : Command("algorithm settings", io, data) {}
};

#endif
