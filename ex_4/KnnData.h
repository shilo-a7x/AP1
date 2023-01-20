#include "KNN.h"

#ifndef KNNDATA_H
#define KNNDATA_H

using namespace std;

template<class T>
class KnnData {
private:
    KNN *Knn;
    vector<T> test;
    vector<string> classified;
public:
    ClientData(KNN *Knn) : knn(knn) {}

    void classify() {
        classified.clear();
        for (auto t: test) {
            classified.push_back(Knn->classify(t));
        }
    }

    KNN *getKnn() const {
        return knn;
    }

    const vector<string> &getClassified() const {
        return classified;
    }

    void setTrain(const vector<T> &v) {
        classifier->setData(v);
    }

    const vector<T> &getTest() const {
        return test;
    }

    void setTest(const std::vector<T> &v) {
        this->test = v;
    }
};


#endif