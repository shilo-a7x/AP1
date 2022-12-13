#include <string>
#include "Distance.cpp"
#include "Classifiable.h"

using namespace std;
class Algorithm
{
private:
    // Standard partition process of QuickSort().
    // It considers the last element as pivot
    // and moves all smaller element to left of
    // it and greater elements to right
    int partition(vector<Classifiable> vectors, int l, int r);
    int K;

public:
    Algorithm();
    int QuickSelect(vector<Classifiable> vectors, int l, int r, int k);
    vector<Classifiable> KClosest(double maxDis, vector<Classifiable> vectors);
    string mostCommon(vector<Classifiable> vectors);
};