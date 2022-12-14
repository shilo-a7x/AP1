#include "KNN.h"

KNN::KNN(string type, int K) : starter(type), algo(K) {}

void KNN::setKNN(string type, int K)
{
    // Sets the K value.
    this->algo.setK(K);

    // Sets the distance measuring type.
    this->starter.setDisFunc(type);
}

string KNN::lunchKNN(vector<Classifiable> &vectors, vector<double> v)
{
    // Initializes all the distances of all the vectors in 'vectors' from 'v'.
    starter.init(vectors, v);

    // Finds the vector that is the K's closest to the given vector.
    double maxDis = algo.QuickSelect(vectors, 0, vectors.size(), this->algo.getK());

    // Picks the k closest vectors from 'Vectors'. in case of ties takes all the ones that their distance is <= maxDis.
    vector<Classifiable> closest = algo.KClosest(maxDis, vectors);

    // Return the string that is the most common among the k closest vectors.
    return algo.mostCommon(closest);
}