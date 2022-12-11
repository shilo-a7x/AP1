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
    public:
        string getLable();
};

#endif