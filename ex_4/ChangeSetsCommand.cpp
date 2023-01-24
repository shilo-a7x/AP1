#include "ChangeSetsCommand.h"
#include <stdexcept>
#include <string>

void ChangeSetsCommand::execute() {
    // write the current settings on the client's screen.
    this->getIO()->write(this->getData()->getKnn()->detailString());

    // read the K and the metric from the client.
    string input = this->getIO()->read();
    if (input.empty()) {
        return;
    }

    // make sure we got 2 arguments.
    vector<string> param = Reader::split(input, ' ');
    if (param.size() != 2) {
        this->getIO()->write("invalid value for K\ninvalid value for metric");
        return;
    }

    // use a flag in order to check if the k is wrong.
    int k, flag = 0;
    string invalid = "";
    try {
        k = stoi(param[0]);
    } catch (const invalid_argument &exception) {
        invalid.append("invalid value for K");
        flag = 1;
    }

    // make sure k is positive.
    if (k < 1 && !flag) {
        invalid.append("invalid value for K");
        flag = 1;
    }

    // check if the metric is valid.
    Distance dist(param[1]);
    if (!dist.isMetricValid()) {
        if (flag){
            invalid.append("\n");
        }
        invalid.append("invalid value for metric");
        flag = 1;
    }
    // if k was bad don't change the settings.
    if (flag) {
        this->getIO()->write(invalid);
        return;
    } else {
        // if everything is ok, change the settings and notify the client.
        this->getIO()->write("OK");
        this->getData()->getKnn()->setKNN(param[1], k);
    }
}


