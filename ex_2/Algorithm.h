#include <string>
#include <map>
#include "Distance.cpp"
#include "Classifiable.h"

using namespace std;

class Algorithm
{
private:
    int partition(vector<Classifiable> &vectors, int l, int r);
    int K;

public:
    Algorithm(int K);
    int getK();
    void setK(int newK);
    double QuickSelect(vector<Classifiable> &vectors, int l, int r, int k);
    vector<Classifiable> KClosest(double maxDis, vector<Classifiable> &vectors);
    string mostCommon(vector<Classifiable> vectors);
};