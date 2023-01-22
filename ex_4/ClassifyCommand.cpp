#include "ClassifyCommand.h"

void ClassifyCommand::execute()
{
    if (this->getData()->getTest().empty())
    {
        this->getIO()->write("please upload data");
        return;
    }
    this->getData()->classify();
    this->getIO()->write("classifying data complete");
}