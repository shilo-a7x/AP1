#include "KNN.h"

KNN::KNN(string type, int K) : starter(type), algo(K) {}

void KNN::setKNN(string type, int K)
{
    // Sets the K value.
    this->algo.setK(K);

    // Sets the distance measuring type.
    this->starter.setDisFunc(type);
}

string KNN::lunchKNN(vector<Classifiable> &vectors, vector<double> &v)
{
    // Initializes all the distances of all the vectors in 'vectors' from 'v'.
    starter.init(vectors, v);

    // get k nearest neighbors to beggining of the array
    algo.QuickSelect(vectors, 0, vectors.size() - 1, algo.getK());

    // Picks the k closest vectors from 'Vectors'.
    vector<Classifiable> closest = algo.KClosest(vectors, algo.getK());

    // Return the string that is the most common among the k closest vectors.
    return algo.mostCommon(closest);
}

int KNN::isDisError()
{
    if (starter.getDisfuncType().compare("ERR"))
    {
        return 1;
    }
    return 0;
}