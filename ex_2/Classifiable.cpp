#include "Classifiable.h"

Classifiable::Classifiable(const vector<string> &v, bool isClassified) : isClassified(isClassified) {
    if (isClassified) {
        for (int i = 0; i < v.size() - 1; i++) {
            coordinates.push_back(stod(v[i]));
        }
        label = v[v.size() - 1];
    } else {
        for (const auto &s : v) {
            coordinates.push_back(stod(s));
        }
    }
}

Classifiable::Classifiable(const Classifiable &unclassified, string label) : isClassified(true) {
    this->label = label;
    coordinates = unclassified.getCoordinates();
}

string Classifiable::getLable() const {
    return label;
}

vector<double> Classifiable::getCoordinates() const {
    return coordinates;
}

double Classifiable::getDistance() const {
    return distance;
}

void Classifiable::setDistance(double d) {
    distance = d;
}

