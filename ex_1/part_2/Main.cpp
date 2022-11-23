#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "VecDistances.h"

using namespace std;

/*
Converts a string to double vectors.
Checks in the procces whether the input is correct.
If it is, returnes 0;
*/
int turnToVector(string stringInput, vector<double> v)
{
    stringstream s(stringInput);
    string token;
    int i;
    double num;

    while (s >> token)
    {
        for (i = 0; i < sizeof(token) - 1; i++)
        {
            if (!isdigit(word[i]))
            {
                return 1;
            }
            num = strtod(word.c_str(), 0);
            v.push_back(num);
        }
    }
    return 0;
}

/*
Calculates the distance between 2 given vectors.
Uses multiple methods of distance calculating.
*/
int main()
{
    string stringInput1, stringInput2;
    vector<double> v1, v2;
    int size, error;

    getline(cin, stringInput1);
    getline(cin, stringInput2);

    error = turnToVector(stringInput1, v1) + turnToVector(stringInput2, v2);
    size = sizeof(v1);

    cout << error << endl;

    if (error || (size != sizeof(v2)))
    {
        cout << "invalid input, goodbye" << endl;
        return 0;
    }

    cout << euclidean(v1, v2, size) << endl;
    cout << manhattan(v1, v2, size) << endl;
    cout << chebyshev(v1, v2, size) << endl;
    cout << canberra(v1, v2, size) << endl;
    cout << minkowski(v1, v2, size, 2) << endl;
    return 0;
}
