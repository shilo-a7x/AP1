#include "Algorithm.h"

Algorithm::Algorithm(int K) {
    this->K = K;
}

int Algorithm::getK() {
    return this->K;
}

void Algorithm::setK(int newK) {
    this->K = newK;
}

int Algorithm::partition(vector<Classifiable> &vectors, int l, int r) {
    // Select a pivot.
    double x = vectors[r].getDistance();
    int i = l, j;

    // Put all the vectors that are smaller then the pivot to it's left and the rest to it's right.
    for (j = l; j <= r - 1; j++) {

        // If the vector's distance is smaller then the pivot's then move it to where will be the pivot's left.
        if (vectors[j].getDistance() <= x) {
            swap(vectors[i], vectors[j]);
            i++;
        }
    }

    // Move the pivot to its right location.
    swap(vectors[i], vectors[r]);
    return i;
}

double Algorithm::QuickSelect(vector<Classifiable> &vectors, int l, int r, int k) {
    // If k is smaller than number of elements in array.
    if (k > 0 && k <= r - l + 1) {

        // Partition the array around last element and get the position of the pivot element in the sorted array.
        int index = partition(vectors, l, r);

        // If the position is the same as K.
        if (index - l == k - 1)
            return vectors[index].getDistance();

        // If the position is smaller then the pivot's location, recur for left subarray
        if (index - l > k - 1)
            return QuickSelect(vectors, l, index - 1, k);

        // Else recur for right subarray
        return QuickSelect(vectors, index + 1, r, k - index + l - 1);
    }

    // If K is more than number of elements in array, take every vector to calculation.
    return 0;
}

vector<Classifiable> Algorithm::KClosest(vector<Classifiable> &vectors, int k) {
    // Create the Kclosest vector.
    vector<Classifiable> Kclosest;
    int i;

    // If the vector's distance is smaller then the given maxDis, add the vector to the Kclosest vector.
    for (i = 0; i <= k; i++) {
        Kclosest.push_back(vectors[i]);
    }
    return Kclosest;
}

string Algorithm::mostCommon(vector<Classifiable> vectors) {
    // Map every string to the number of time is occuers.
    map<string, int> map;
    int i, max = 0;
    string mostCommonString;

    // Check for every vector if it's string is in the map. if so then ++ it, if not add it to the map.
    for (i = 0; i < vectors.size(); i++) {
        string current = vectors[i].getLable();
        if (map.count(current) == 0) {
            map[current] = 0;
        }
        map[current]++;
    }

    // Get the most coomon value from the map.
    for (const auto &pair : map) {
        if (max < pair.second) {
            max = pair.second;
            mostCommonString = pair.first;
        }
    }
    return mostCommonString;
}