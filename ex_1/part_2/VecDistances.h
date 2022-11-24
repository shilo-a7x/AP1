// header file for the vecdistances.cpp file.
#include <cmath>
#include <vector>

using namespace std;

double euclidean(vector<double> vec1, vector<double> vec2, int size);
double manhattan(vector<double> vec1, vector<double> vec2, int size);
double chebyshev(vector<double> vec1, vector<double> vec2, int size);
double canberra(vector<double> vec1, vector<double> vec2, int size);
double minkowski(vector<double> vec1, vector<double> vec2, int size, double r);