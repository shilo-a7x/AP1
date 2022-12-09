#include "Algorithm.h"
#include "Distance.cpp"

class Algorithm
{
private:
    Distance disFunc;

public:
    Algorithm(string type)
    {
        this->disFunc = Distance(type);
        string err = disFunc.getType;
        if (err.compare("ERR"))
        {
            cout << "wrong distance input" << endl;
            this->disFunc = nullptr;
        }
    }
};