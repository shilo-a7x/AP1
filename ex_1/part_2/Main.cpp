#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "VecDistances.h"

using namespace std;

// bool is_number(const string& s)
// {
// string::const_iterator it = s.begin();
// while (it != s.end() && std::isdigit(*it)) ++it;
// return !s.empty() && it == s.end();
// }

bool is_number(const string& s)
{
    long double ld;
    return((istringstream(s) >> ld >> ws).eof());
}


/*
Converts a string to double vectors.
Checks in the procces whether the input is correct.
If it is, returnes 0;
*/
int turnToVector(string stringInput, vector<double> &v)
{
    stringstream s(stringInput);
    string token;
    double num;

    while (s >> token)
    {
        if (!is_number(token))
        {
            return 1;
        }
        num = strtod(token.c_str(), 0);
        v.push_back(num);
    }
    return 0;
}

void printDistance(double dis)
{
    if (floor(dis) == ceil(dis))
    {
        fixed(cout);
        cout.precision(1);
    }
    else
    {
        fixed(cout);
        cout.precision(16);
    }
    cout << dis << endl;
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
    size = v1.size();

    if (error || (size != v2.size()))
    {
        cout << "invalid input, goodbye" << endl;
        return 0;
    }

    printDistance(euclidean(v1, v2, size));
    printDistance(manhattan(v1, v2, size));
    printDistance(chebyshev(v1, v2, size));
    printDistance(canberra(v1, v2, size));
    printDistance(minkowski(v1, v2, size, 2));
    return 0;
}
