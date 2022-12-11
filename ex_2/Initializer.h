#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <iostream>
#include <vector>
#include "Distance.cpp"
#include "Classifiable.h"

using namespace std;

class Initializer {
    private:
        Distance disFunc;
    public:
        Initializer (string type);
        vector<Classifiable> init(vector<Classifiable> vectors, vector<double> v);
};








#endif
