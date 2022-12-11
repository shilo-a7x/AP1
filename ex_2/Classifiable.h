#ifndef CLASSIFIABLE_H
#define CLASSIFIABLE_H

#include <vector>
#include <string>

using namespace std;

class Classifiable {
    private:
        string label;
        vector<double> coordinates;
        bool isClassified;
        double distance = 0;
    public:
        string getLable();
        double setDistance();
        double getDistance();
        vector<Classifiable> toVector(const vector<vector<string>> &data, bool isClassified);
};

#endif