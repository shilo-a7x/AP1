#ifndef KNN_H
#define KNN_H

#include <vector>
#include "Classifiable.h"
#include "Initializer.h"
#include "Algorithm.cpp"

using namespace std;

class KNN {
    private:
        Initializer initializer;
        Algorithm algorithm;
    public:
        KNN (string type);

        string fftAlgorithm(vector<Classifiable> vectors);
};

#endif