#include "UploadCommand.h"
#include <iostream>

void UploadCommand::execute()
{
    this->getIO()->write("Please upload your local train CSV file.");
    string input = this->getIO()->read();
    if (input == "ERROR")
    {
        return;
    }
    try
    {
        this->getData()->setTrain(Classifiable::stringToVector(input, true));
    }
    catch (const exception &e)
    {
        this->getIO()->write("invalid input");
        this->getIO()->read();
        return;
    }
    this->getIO()->write("Upload Complete.");
    this->getIO()->read();
    this->getIO()->write("Please upload your local test CSV file.");
    input = this->getIO()->read();
    if (input == "ERROR")
    {
        return;
    }
    try
    {
        this->getData()->setTest(Classifiable::stringToVector(input, false));
    }
    catch (const exception &e)
    {
        this->getIO()->write("invalid input");
        this->getIO()->read();
        return;
    }
    this->getIO()->write("Upload Complete");
    this->getIO()->read();
}