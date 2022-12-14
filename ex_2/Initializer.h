#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <vector>
#include "Distance.cpp"
#include "Classifiable.h"

using namespace std;

class Initializer {
    private:
        Distance disFunc;
    public:
        Initializer (string type);
        void setDistance(string newDis);
        vector<Classifiable> init(vector<Classifiable> vectors, vector<double> v);

};

#endif