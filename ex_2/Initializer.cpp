#include "Initializer.h"

Initializer::Initializer(string type)
{
    this->disFunc = Distance(type);
        string err = disFunc.getType;
        if (err.compare("ERR"))
        {
            cout << "wrong distance input" << endl;
            this->disFunc = nullptr;
        }
}

vector<Classifiable> Initializer::init(vector<Classifiable> vectors, vector<double> v)
{
    int i;
    for(i=0; i<vectors.size(); i++){
        vectors[i].setDistance(disFunc.dis(v,vectors[i].getCoordinates()));
    }
    return vectors;
}