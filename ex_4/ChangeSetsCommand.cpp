#include "ChangeSetsCommand.h"
#include <stdexcept>
#include <string>
#include <iostream>

void ChangeSetsCommand::execute()
{
    // write the current settings on the client's screen.
    this->getIO()->write(this->getData()->getKnn()->detailString());

    string s = "";
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
        s.append("invalid value for K\ninvalid value for metric");
        this->getIO()->write(s);
        this->getIO()->read();
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
        s.append("invalid value for K");
        flag = 1;
    }

    // make sure k is positive.
    if (k < 1 && !flag)
    {
        s.append("invalid value for K");
        flag = 1;
    }

    // check if the metric is valid.
    Distance dist(param[1]);
    if (!dist.isMetricValid())
    {
        if (flag)
        {
            s.append("\n");
        }
        s.append("invalid value for metric");
        flag = 1;
    }
    // if k was bad don't change the settings.
    if (flag)
    {
        this->getIO()->write(s);
        this->getIO()->read();
        return;
    }
    else
    {
        // if everything is ok, change the settings and notify the client.
        this->getData()->getKnn()->setKNN(param[1], k);
    }
}
