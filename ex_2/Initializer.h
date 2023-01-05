/*
header for the Initializer class.
*/

#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <vector>
#include "Distance.h"
#include "Classifiable.h"

using namespace std;

class Initializer
{
private:
    /*
    Defines which distance method will be used during the initialization.
    */
    Distance disFunc;

public:
    /*
    Constructor function.
    */
    Initializer(string type);

    /*
    Setter for the disFunc parameter.
    */
    void setDisFunc(string newDis);

    /*
    Getter for the type of the disFunc parameter.
    */
    string GetDisType();

    /*
    Initializes all the distance parameters of the vectors according to a given vector
    */
    vector<Classifiable> init(vector<Classifiable> &vectors, vector<double> v);
};

#endif
