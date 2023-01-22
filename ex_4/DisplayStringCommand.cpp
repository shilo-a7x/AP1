#include "DisplayStringCommand.h"

void DisplayStringCommand::execute()
{
    if (this->getData()->getTest().empty())
    {
        this->getIO()->write("please upload data");
        return;
    }

    if (this->getData()->getClassifiedStrings().empty())
    {
        this->getIO()->write("please classify the data");
        return;
    }

    for (int i = 0; i < this->getData()->getClassifiedStrings().size(); i++)
    {
        this->getIO()->write(to_string(i + 1) + '\t' + this->getData()->getClassifiedStrings()[i]);
    }
    this->getIO()->write("Done.");

    // Waiting for client to press enter.
    this->getIO()->read();
}