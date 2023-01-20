#include "KnnData.h"

void KnnData::classify()
{
    sclassified.clear();
    for (Classifiable t : unclassified)
    {
        vector<double> tc = t.getCoordinates();
        t.setLable(knn->lunchKNN(classified, tc));
        sclassified.push_back(t.getLable());
    }
}

KNN *KnnData::getKnn() const
{
    return knn;
}

const vector<string> &KnnData::getClassifiedStrings() const
{
    return sclassified;
}

void KnnData::setClassified(const vector<Classifiable> &v)
{
    this->classified = v;
}

const vector<Classifiable> &KnnData::getUnclassified() const
{
    return unclassified;
}

void KnnData::setUnclassified(const vector<Classifiable> &v)
{
    this->unclassified = v;
}