#include "Distance.h"

Distance::Distance(string type) {
    // Makes sure that the distance type we are using is legit.
    if (!type.compare("MAN") || !type.compare("AUC") || !type.compare("CHB") || !type.compare("CAN") || !type.compare("MIN")) {
        this->type = type;
    }

    // Puts 'ERR' in the string.
    else {
        this->type = "ERR";
    }
}

string Distance::getType() {
    return this->type;
}

void Distance::setType(string newType) {
    this->type = newType;
}

double Distance::dis(vector<double> vec1, vector<double> vec2) {
    if (!this->type.compare("MAN")) {
        return this->manhattan(vec1, vec2, vec1.size());
    }
    if (!this->type.compare("AUC")) {
        return this->euclidean(vec1, vec2, vec1.size());
    }
    if (!this->type.compare("CHB")) {
        return this->chebyshev(vec1, vec2, vec1.size());
    }
    if (!this->type.compare("CAN")) {
        return this->canberra(vec1, vec2, vec1.size());
    }
    if (!this->type.compare("MIN")) {
        return this->minkowski(vec1, vec2, vec1.size());
    }

    // If the type is not valid then just take all the vectors.
    return 0;
}

double Distance::euclidean(vector<double> vec1, vector<double> vec2, int size) {
    // get the distance using the minkowsky distance with p=2.
    return minkowski(vec1, vec2, size, 2);
}

double Distance::manhattan(vector<double> vec1, vector<double> vec2, int size) {
    // get the distance using the minkowsky distance with p=1.
    return minkowski(vec1, vec2, size, 1);
}

double Distance::chebyshev(vector<double> vec1, vector<double> vec2, int size) {
    double max = 0;
    int i;

    // a way to calculate the chebyshev distance.
    // picking the max distance between any two coordinates.
    for (i = 0; i < size; i++) {
        if (max < abs(vec1[i] - vec2[i])) {
            max = abs(vec1[i] - vec2[i]);
        }
    }
    return max;
}

double Distance::canberra(vector<double> vec1, vector<double> vec2, int size) {
    int i;
    double sum = 0;

    // calculate the distance by implementing the canberra distance formula.
    for (i = 0; i < size; i++) {
        if (vec2[i] != 0 || vec1[i] != 0) {
            sum += (abs(vec1[i] - vec2[i])) / (abs(vec1[i]) + abs(vec2[i]));
        }
    }
    return sum;
}

double Distance::minkowski(vector<double> vec1, vector<double> vec2, int size, double p) {
    double sum = 0;
    int i;

    // calculate the distance by implementing the minkowski distance formula for a given p.
    for (i = 0; i < size; i++) {
        sum += pow(abs(vec1[i] - vec2[i]), p);
    }
    return pow(sum, 1.0 / p);
}
