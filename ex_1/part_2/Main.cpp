#include <iostream>
#include <string.h>
#include "VecDistances.h"

using namespace std;

/*
Calculates the distance between 2 given vectors.
Uses multiple methods of distance calculating.
*/
void main()
{
    string vec1, vec2;
    double ** vectors;

    getline(cin, vec1);
    getline(cin, vec2);
    while (!validInput(vec1, vec2, vectors))
    {
        cout << "wrong input, type again\n";
        getline(cin, vec1);
        getline(cin, vec2);
    }
}

/*
Checks if the input is correct.
If it is, calls a function that converts the vectors to double arrays.
*/
int validInput(string vec1, string ves2, double **vectors)
{
    
}
