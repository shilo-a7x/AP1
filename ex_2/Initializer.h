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
        Initializer (Distance disFunc);
        vector<Classifiable> init(vector<Classifiable> vectors, vector<double> v);
};







#endif
