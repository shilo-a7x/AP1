/*
header for the Algorithm class.
*/

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <map>
#include "Distance.h"
#include "Classifiable.h"

using namespace std;

class Algorithm
{
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
    */
    double QuickSelect(vector<Classifiable> &vectors, int l, int r, int k);

    /*
    Gets a distance and returns all the vectors that their distances are <= maxDis.
    */
    vector<Classifiable> KClosest(double maxDis, vector<Classifiable> &vectors);

    /*
    Returns the most common string among all the Classifiables in a given Classifiable vector.
    */
    string mostCommon(vector<Classifiable> vectors);
};

#endif