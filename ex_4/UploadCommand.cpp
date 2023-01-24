#include "UploadCommand.h"

void UploadCommand::execute() {
    this->getIO()->write("Please upload your local train CSV file.");
    string input = this->getIO()->read();
    if (input.empty()) {
        this->getIO()->write("invalid input");
        return;
    }
    try {
        this->getData()->setTrain(Classifiable::stringToVector(input, true));
    } catch (const exception &e) {
        this->getIO()->write("invalid input");
        return;
    }
    this->getIO()->write("Upload Complete.");
    this->getIO()->write("Please upload your local test CSV file.");
    input = this->getIO()->read();
    if (input.empty()) {
        this->getIO()->write("invalid input");
        return;
    }
    try {
        this->getData()->setTest(Classifiable::stringToVector(input, false));
    } catch (const exception &e) {
        this->getIO()->write("invalid input");
        return;
    }
    this->getIO()->write("Upload Complete");
}
