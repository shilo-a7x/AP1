#include "KnnData.h"

void KnnData::classify() {
    sclassified.clear();
    for (Classifiable t : test) {
        vector<double> tc = t.getCoordinates();
        t.setLable(knn->lunchKNN(train, tc));
        sclassified.push_back(t.getLable());
    }
}

KNN *KnnData::getKnn() const {
    return knn;
}

const vector<string> &KnnData::getClassifiedStrings() const {
    return sclassified;
}

void KnnData::setTrain(const vector<Classifiable> &v) {
    this->train = v;
}

const vector<Classifiable> &KnnData::getTest() const {
    return test;
}

void KnnData::setTest(const vector<Classifiable> &v) {
    this->test = v;
}