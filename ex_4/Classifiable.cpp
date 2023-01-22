#include "Classifiable.h"
#include "Reader.h"
#include <stdexcept>

Classifiable::Classifiable(const vector<string> &v, bool isClassified) : isClassified(isClassified)
{
    if (isClassified)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            coordinates.push_back(stod(v[i]));
        }
        label = v[v.size() - 1];
    }
    else
    {
        for (const auto &s : v)
        {
            coordinates.push_back(stod(s));
        }
    }
}

Classifiable::Classifiable(const Classifiable &unclassified, string label) : isClassified(true)
{
    this->label = label;
    coordinates = unclassified.getCoordinates();
}

string Classifiable::getLable() const 
{
    return label;
}

void Classifiable::setLable(string l)
{
    this->label = l;
    this->isClassified = true;
}

vector<double> Classifiable::getCoordinates() const
{
    return coordinates;
}

double Classifiable::getDistance() const
{
    return distance;
}

void Classifiable::setDistance(double d)
{
    distance = d;
}

vector<Classifiable> Classifiable::toVector(const vector<vector<string>> &data, bool isClassified)
{
    vector<Classifiable> vOut;
    for (const auto &v : data)
    {
        vOut.push_back(Classifiable(v, isClassified));
    }
    return vOut;
}

vector<Classifiable> Classifiable::stringToVector(const string &data, bool isClassified) {
    vector<string> elements = Reader::split(data, '\n');
    vector<Classifiable> out;
    int length = Reader::split(elements[0], ',').size();
    for (const string &e : elements) {
        vector<string> coordinates = Reader::split(e, ',');
        if (coordinates.size() != length) {
            throw invalid_argument("Classifiables dimensions must agree");
        }
        try {
            out.emplace_back(coordinates, isClassified);
        } catch (const exception &e) {
            throw invalid_argument("Invalid coordinates");
        }
    }
    return out;
}