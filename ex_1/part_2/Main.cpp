#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "VecDistances.h"

using namespace std;

/*
Calculates the distance between 2 given vectors.
Uses multiple methods of distance calculating.
*/
int main()
{
    string vec1, vec2, word;
    double num;
    vector<double> v1, v2;

    getline(cin, vec1);
    getline(cin, vec2);
    
    stringstream v1(vec1);
    while (v1 >> word){
        if (!is digit(word[0])){

        }
    }
    s(vec1);

    turnToVectors(vec1, vec2);

    if (!validInput)
    {
        cout << "invalid input, goodbye" return 0;
    }
    int size = sizeof(vectors[0]);
    cout << euclidean(vectors[0], vectors[1], size) << endl 
    cout << manhattan(vectors[0], vectors[1], size) << endl 
    cout << chebyshev(vectors[0], vectors[1], size) << endl 
    cout << canberra(vectors[0], vectors[1], size) << endl 
    cout << minkowski(vectors[0], vectors[1], size, 2) << endl return 0;
}

/*
Checks if the input is correct.
If it is, converts the vectors to double arrays in the procces.
*/
int validInput(string vec1, string ves2){
    vectors[0] = nu

turnToVectors()
{
}