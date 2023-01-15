/*
header for the Algorithm class.
*/

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Classifiable.h"
#include "Distance.h"
#include <map>
#include <string>

using namespace std;

class Algorithm {
private:
    /*
    Defines how many vectors we need to take for the string picking.
    */
    int K;

    /*
    Standard partition process of QuickSort().
    Considers the last element as pivot and moves all smaller element to it's left greater elements to it's right.
    Helps the QuickSelect function with it's algorithm.
    */
    int partition(vector<Classifiable> &vectors, int l, int r);

public:
    /*
    Constructor function.
    */
    Algorithm(int K);

    /*
    Getter for the K parameter.
    */
    int getK();

    /*
    Setter for the K parameter.
    */
    void setK(int newK);

    /*
    Uses an algorithm similar to QuickSort() in order to find the K's smallest element.
    Instead of sorting both sides after the partition sorts recursively only the side where K is in.
    ints l, r and k are indices, so init with [0, size - 1, k]
    */
    double QuickSelect(vector<Classifiable> &vectors, int l, int r, int k);

    /*
    Returns a vector of the k smallest elements
    */
    vector<Classifiable> KClosest(vector<Classifiable> &vectors, int k);

    /*
    Returns the most common string among all the Classifiables in a given Classifiable vector.
    */
    string mostCommon(vector<Classifiable> vectors);
};

#endif