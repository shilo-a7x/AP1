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

    void classify()
    {
        sclassified.clear();
        for (Classifiable t : unclassified)
        {
            vector<double> tc = t.getCoordinates();
            t.setLable(knn->lunchKNN(classified, tc));
            sclassified.push_back(t.getLable());
        }
    }

    KNN *getKnn() const
    {
        return knn;
    }

    const vector<string> &getClassifiedStrings() const
    {
        return sclassified;
    }

    void setClassified(const vector<Classifiable> &v)
    {
        this->classified = v;
    }

    const vector<Classifiable> &getUnclassified() const
    {
        return unclassified;
    }

    void setUnclassified(const vector<Classifiable> &v)
    {
        this->unclassified = v;
    }
};

#endif