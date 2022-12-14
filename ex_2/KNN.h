/*
h-fine for the KNN class.
*/

#ifndef KNN_H
#define KNN_H

#include <vector>
#include "Classifiable.h"
#include "Initializer.h"
#include "Algorithm.h"

using namespace std;

class KNN
{
private:

    /*
    Two classes that holds the functions that KNN uses.
    */
    Initializer starter;
    Algorithm algo;

public:
    /*
    Constructor function.
    */
    KNN(string type, int K);

    /*
    Sets the K value and the distance measuring type of the KNN algorithm to new ones.
    */
    void setKNN(string type, int K);

    /*
    Uses KNN's members in order to return the most common string in the K closets vectors.
    */
    string lunchKNN(vector<Classifiable> &vectors, vector<double> v);
};

#endif