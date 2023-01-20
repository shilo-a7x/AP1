#include "KNN.h"

#ifndef KNNDATA_H
#define KNNDATA_H

using namespace std;

class KnnData
{
private:
    KNN *knn;
    vector<Classifiable> unclassified;
    vector<Classifiable> classified;
    vector<string> sclassified;

public:
    KnnData(KNN *Knn) : knn(Knn) {}

    void classify();

    KNN *getKnn() const;

    const vector<string> &getClassifiedStrings() const;

    void setClassified(const vector<Classifiable> &v);

    const vector<Classifiable> &getUnclassified() const;

    void setUnclassified(const vector<Classifiable> &v);
};

#endif