#include "CLI.h"

void CLI::printMenu()
{
    string msg = "Welcome to the KNN Classifier Server. Please choose an option:";
    for (int i = 0; i < commands.size(); i++)
    {
        msg.append("\n" + to_string(i + 1) + ". " + commands[i]->getDescription());
    }
    msg.append("\n8. exit");
    io->write(msg);
}

void CLI::run()
{
    while (true)
    {
        printMenu();
        string option = io->read();
        int optionNumber;
        try
        {
            optionNumber = stoi(option) - 1;
        }
        catch (const exception &e)
        {
            continue;
        }
        if (optionNumber == 7)
        {
            break;
        }
        if (optionNumber < 0 || optionNumber > 4)
        {
            continue;
        }
        commands[optionNumber]->execute();
    }
}