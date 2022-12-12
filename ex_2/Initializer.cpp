#include "Initializer.h"

Initializer::Initializer(string type) : disFunc(type) {}

vector<Classifiable> Initializer::init(vector<Classifiable> vectors, vector<double> v)
{
    int i;
    for (i = 0; i < vectors.size(); i++)
    {
        vectors[i].setDistance(disFunc.dis(v, vectors[i].getCoordinates()));
    }
    return vectors;
}