#include "Initializer.h"

Initializer::Initializer(string type) : disFunc(type) {}

void Initializer::setDisFunc(string newDis)
{

    // Sets the distance type the initializer is working with.
    this->disFunc.setType(newDis);
}

vector<Classifiable> Initializer::init(vector<Classifiable> &vectors, vector<double> v)
{
    int i;

    // Sets the distance for each vector in 'vectors'.
    for (i = 0; i < vectors.size(); i++)
    {
        vectors[i].setDistance(disFunc.dis(v, vectors[i].getCoordinates()));
    }
    return vectors;
}

string Initializer::getDisfuncType()
{
    return disFunc.getType();
}