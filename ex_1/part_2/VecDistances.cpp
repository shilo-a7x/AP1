#include "VecDistances.h"

double euclidean(vector<double> vec1, vector<double> vec2, int size)
{
    return minkowski(vec1, vec2, size, 2);
}

double manhattan(vector<double> vec1, vector<double> vec2, int size)
{
    return minkowski(vec1, vec2, size, 1);
}

double chebyshev(vector<double> vec1, vector<double> vec2, int size)
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
    return max;
}

double canberra(vector<double> vec1, vector<double> vec2, int size)
{
    int i;
    double sum = 0;
    for (i = 0; i < size; i++)
    {
        if (vec2[i] != 0 || vec1[i] != 0)
        {
            sum += (abs(vec1[i] - vec2[i])) / (abs(vec1[i]) + abs(vec2[i]));
        }
    }
    return sum;
}

double minkowski(vector<double> vec1, vector<double> vec2, int size, double r)
{
    double sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += pow(abs(vec1[i] - vec2[i]), r);
    }
    return pow(sum, 1.0 / r);
}
