#include "ClassifyCommand.h"

void ClassifyCommand::execute()
{
    if (this->getData()->getTest().empty())
    {
        this->getIO()->write("please upload data");
        this->getIO()->read();
        return;
    }
    this->getData()->classify();
    this->getIO()->write("classifying data complete");
    this->getIO()->read();
}
