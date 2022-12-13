#include "KNN.h"

KNN::KNN(string type, int K) : starter(type) , algo(K) {}

string KNN::lunchKNN(vector<Classifiable> &vectors, vector<double> v)
{
    starter.init(vectors, v);
    double maxDis = algo.QuickSelect(vectors, 0, vectors.size(), this->algo.getK());
    vector<Classifiable> closest= algo.KClosest(maxDis, vectors);
    return algo.mostCommon(closest);
}