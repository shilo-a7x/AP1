#include "Command.h"
#include "Reader.h"
#include "Distance.h"

#ifndef CLIENT_CHANGEALGOSETTINGS_H
#define CLIENT_CHANGEALGOSETTINGS_H

using namespace std;

class ChangeAlgoSettingsCommand : public Command
{
public:
    void execute() override
    {
        this->getIO()->write(this->getData()->getKnn()->detailString());
        string input = this->getIO()->read();
        if (input.empty())
        {
            return;
        }
        vector<string> param = Reader::split(input, ' ');
        if (param.size() != 2)
        {
            this->getIO()->write("invalid value for K\ninvalid value for metric\n");
            return;
        }
        int k, flag = 0;
        try
        {
            k = stoi(param[0]);
        }
        catch (const invalid_argument &exception)
        {
            this->getIO()->write("invalid value for K\n");
            flag = 1;
        }
        if (k < 0 && !flag)
        {
            this->getIO()->write("invalid value for K\n");
            flag = 1;
        }
        Distance dist(param[1]);
        if (!dist.getType().compare("ERR"))
        {
            this->getIO()->write("invalid value for metric\n");
            return;
        }
        else
        {
            if (flag)
            {
                return;
            }
            else
            {
                this->getData()->getKnn()->setKNN(param[1], k);
            }
        }
    }

    ChangeAlgoSettingsCommand(DefaultIO *io, KnnData *data) : Command("algorithm settings", io, data) {}
};

#endif // CLIENT_CHANGEALGOSETTINGS_H