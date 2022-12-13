#ifndef KNN_H
#define KNN_H

#include <vector>
#include "Classifiable.h"
#include "Initializer.h"
#include "Algorithm.cpp"

using namespace std;

class KNN
{
private:
    Initializer starter;
    Algorithm algo;

public:
    KNN(string type, int K);
    string lunchKNN(vector<Classifiable> &vectors, vector<double> v);
};

#endif