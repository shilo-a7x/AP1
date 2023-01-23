#include "KNN.h"

#ifndef KNNDATA_H
#define KNNDATA_H

using namespace std;

class KnnData {
private:
    KNN *knn;
    vector<Classifiable> test;
    vector<Classifiable> train;
    vector<string> sclassified;

public:
    KnnData(KNN *Knn) : knn(Knn) {}

    void classify();

    KNN *getKnn() const;

    const vector<string> &getClassifiedStrings() const;

    void setTrain(const vector<Classifiable> &v);

    const vector<Classifiable> &getTest() const;

    void setTest(const vector<Classifiable> &v);
};

#endif