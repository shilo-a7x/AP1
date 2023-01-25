#include "DownloadResultsCommand.h"

void DownloadResultsCommand::execute() {
    if (this->getData()->getTest().empty()) {
        this->getIO()->write("please upload data");
        this->getIO()->read();
        return;
    }

    if (this->getData()->getClassifiedStrings().empty()) {
        this->getIO()->write("please classify the data");
        this->getIO()->read();
        return;
    }
    this->getIO()->write("enter a path for the csv file");
    this->getIO()->read();
    ostringstream msg;
    // Encapsulate the message in order for it to be saved instead of printed
    for (int i = 0; i < this->getData()->getClassifiedStrings().size(); i++) {
        msg << to_string(i + 1) + '\t' + this->getData()->getClassifiedStrings()[i] << "\n";
    }

    this->getIO()->write(msg.str());
}
