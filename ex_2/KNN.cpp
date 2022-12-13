#include "KNN.h"

KNN::KNN(string type, int K) : starter(type) , algo(K) {}

string lunchKNN(vector<Classifiable> vectors)
{
    this.starter.init(vectors);
    this.algo.QuickSelect(vectors)
}