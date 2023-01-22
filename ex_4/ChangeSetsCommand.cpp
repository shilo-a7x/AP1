#include "ChangeSetsCommand.h"

void ChangeSetsCommand::execute()
    {
        // write the current settings on the client's screen.  
        this->getIO()->write(this->getData()->getKnn()->detailString());

        // read the K and the metric from the client.
        string input = this->getIO()->read();
        if (input.empty())
        {
            return;
        }

        // make sure we got 2 arguments.
        vector<string> param = Reader::split(input, ' ');
        if (param.size() != 2)
        {
            this->getIO()->write("invalid value for K\ninvalid value for metric");
            return;
        }

        // use a flag in order to check if the k is wrong.
        int k, flag = 0;
        try
        {
            k = stoi(param[0]);
        }
        catch (const invalid_argument &exception)
        {
            this->getIO()->write("invalid value for K");
            flag = 1;
        }

        // make sure k is positive.
        if (k < 1 && !flag)
        {
            this->getIO()->write("invalid value for K");
            flag = 1;
        }

        // check if the metir is legal.
        Distance dist(param[1]);
        if (!dist.getType().compare("ERR"))
        {
            this->getIO()->write("invalid value for metric");
            return;
        }
        else
        {
            // if k was bad don't change the settings.
            if (flag)
            {
                return;
            }

            // if everything is ok, change the settings.
            else
            {
                this->getData()->getKnn()->setKNN(param[1], k);
            }
        }
    }
