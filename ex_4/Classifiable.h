#ifndef CLASSIFIABLE_H
#define CLASSIFIABLE_H

#include <string>
#include <vector>

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
    // a distance from a specific classifiable
    double distance = 0;

public:
    /**
     * @brief Construct a new Classifiable object from a string vector.
     * label (if exist) is on last element of the vector.
     *
     * @param v string vector
     * @param isClassified
     */
    Classifiable(const vector<string> &v, bool isClassified);
    /**
     * @brief Construct a new Classifiable object from unclassified
     * and gives it a classification
     *
     * @param unclassified
     * @param label
     */
    Classifiable(const Classifiable &unclassified, string label);
    /**
     * @brief Get the classification
     *
     * @return string
     */
    string getLable() const;
    /**
     * @brief Get the coordinates of the classifiable object
     *
     * @return vector<double>
     */
    vector<double> getCoordinates() const;
    /**
     * @brief Get the distance from antother object
     *
     * @return double
     */
    double getDistance() const;
    /**
     * @brief Set the distance from another object
     *
     * @param d
     */
    void setDistance(double d);
    /**
     * @brief Convert a string matrix into a vector of classifiables
     *
     * @param data string matrix (classification expected to be on last column)
     * @param isClassified
     * @return vector<Classifiable>
     */
    static vector<Classifiable> toVector(const vector<vector<string>> &data, bool isClassified);

    /**
     * @brief Convert a string (csv format) into a vector of classifiables
     *
     * @param data string of classifiables (csv format)
     * @param isClassified
     * @return vector<Classifiable>
     */
    static vector<Classifiable> stringToVector(const string &data, bool isClassified);
};

#endif