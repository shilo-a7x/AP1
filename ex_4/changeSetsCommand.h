#include "Command.h"

#ifndef CLIENT_CHANGEALGOSETTINGS_H
#define CLIENT_CHANGEALGOSETTINGS_H

using namespace std;

class ChangeAlgoSettingsCommand : public Command {
public:
    void execute() override {
        this->getIO()->write(this->getData()->getKnn()->detailString());
        string input = this->getIO()->read();
        if (input.empty()) {
            return;
        }
        vector<string> parameters = utils::split(input, ' ');
        if (parameters.size() != 2) {
            this->getIO()->write("Expected 2 parameters");
            return;
        }
        int k;
        try {
            k = stoi(parameters[0]);
        }
        catch (const invalid_argument &exception) {
            this->getIO()->write("K should be an int");
            return;
        }

        if (k > 10 || k < 1) {
            this->getIO()->write("K should be between 1 and 10");
            return;
        }
        std::unique_ptr<Distance<T>> newDistance;
        std::string inputDistance = parameters[1];
        std::transform(inputDistance.begin(), inputDistance.end(), inputDistance.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        if (inputDistance == "che") {
            newDistance = std::make_unique<ChebyshevDistance<T>>();
        } else if (inputDistance == "man") {
            newDistance = std::make_unique<ManhattanDistance<T>>();
        } else if (inputDistance == "euc") {
            newDistance = std::make_unique<EuclideanDistance<T>>();
        } else {
            this->getIO()->write("Invalid distance metric");
            return;
        }
        this->getData()->getClassifier()->setK(k);
        this->getData()->getClassifier()->setDistance(newDistance);
        this->getIO()->write(this->getData()->getClassifier()->toString());
    }

    ChangeAlgoSettingsCommand(DefaultIO *io, ClientData<T> *data) :
            Command<T>("algorithm settings", io, data) {}
};


#endif //CLIENT_CHANGEALGOSETTINGS_H