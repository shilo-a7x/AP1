/*
header for the Distance class.
*/

#ifndef DISTANCE_H
#define DISTANCE_H

#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Distance {
private:
    /*
    A string which defines which distance method to use.
    */
    string type;

    /*
    Calculates the euclidean distance between two given vectors.
    */
    double euclidean(vector<double> vec1, vector<double> vec2, int size);

    /*
    Calculates the manhattan distance between two given vectors.
    */
    double manhattan(vector<double> vec1, vector<double> vec2, int size);

    /*
    Calculates the chebyshev distance between two given vectors.
    */
    double chebyshev(vector<double> vec1, vector<double> vec2, int size);

    /*
    Calculates the canberra distance between two given vectors.
    */
    double canberra(vector<double> vec1, vector<double> vec2, int size);

    /*
    Calculates the minkowski distance between two given vectors.
    */
    double minkowski(vector<double> vec1, vector<double> vec2, int size, double p = 3);

public:
    /*
    Constructor function
    */
    Distance(string type);

    /*
    Getter for the type parameter.
    */
    string getType();

    /*
   Setter for the type parameter.
   */
    void setType(string newType);

    /*
    Determines which distance function to apply once called.
    */
    double dis(vector<double> vec1, vector<double> vec2);
};

#endif