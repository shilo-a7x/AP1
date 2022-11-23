#include "VecDistances.h"
#include <math.h>

double euclidean(double *vec1, double *vec2, int size)
{
    int i;
    double sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += (vec1[i] - vec2[i]) * (vec1[i] - vec2[i]);
    }
    return sqrt(sum);
}

double manhattan(double *vec1, double *vec2, int size)
{
    int i;
    double sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += abs(vec1[i] - vec2[i]);
    }
    return sum;
}

double chebyshev(double *vec1, double *vec2, int size)
{
    double max = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (max < abs(vec1[i] - vec2[i]))
        {
            max = abs(vec1[i] - vec2[i]);
        }
    }
}

double canberra(double *vec1, double *vec2, int size)
{
    int i;
    double sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += (abs(vec1[i] - vec2[i])) / (abs(vec1[i]) + abs(vec2[i]));
    }
    return sum;
}

double minkowski(double *vec1, double *vec2, int size, double r)
{
    double sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += power(x[i] - y[i], r);
    }
    return power(sum, 1.0 / r);
}