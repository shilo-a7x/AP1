#include "DisplayStringCommand.h"

void DisplayStringCommand::execute()
{
    if (this->getData()->getTest().empty())
    {
        this->getIO()->write("please upload data");
        this->getIO()->read();
        return;
    }

    if (this->getData()->getClassifiedStrings().empty())
    {
        this->getIO()->write("please classify the data");
        return;
    }
    ostringstream msg;
    for (int i = 0; i < this->getData()->getClassifiedStrings().size(); i++)
    {
        msg << (to_string(i + 1) + '\t' + this->getData()->getClassifiedStrings()[i]) << "\n";
    }
    msg << "Done.";
    this->getIO()->write(msg.str());

    // Waiting for client to press enter.
    this->getIO()->read();
}
