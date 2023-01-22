#include "DownloadResultsCommand.h"

void DownloadResultsCommand::execute()
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

    
}