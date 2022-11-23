#include <cmath>

using namespace std;
double euclidean(double* vec1, double* vec2, int size);
double manhattan(double* vec1, double* vec2, int size);
double chebyshev(double *vec1, double *vec2, int size);
double canberra(double *vec1, double *vec2, int size);
double minkowski(double *vec1, double *vec2, int size, double r);