#ifndef CLASSIFIABLE_H
#define CLASSIFIABLE_H

#include <vector>
#include <string>

using namespace std;
/**
 * @brief This class represents an object with coordinates 
 * which can be classified.
 * 
 */
class Classifiable {
    private:
        // the classification
        string label;
        vector<double> coordinates;
        bool isClassified;
        // a distance from a specific classi
        double distance = 0;
    public:
        Classifiable(const vector<string> &v, bool isClassified);
        Classifiable(const Classifiable &unclassified, string label);
        string getLable() const;
        vector<double> getCoordinates() const;
        double getDistance() const;
        void setDistance(double d);
        static vector<Classifiable> toVector(const vector<vector<string>> &data, bool isClassified);
};

#endif