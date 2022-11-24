// header file for the main.cpp file. 
#include <iostream>
#include <sstream>
#include <vector>
#include "VecDistances.h"

using namespace std;

bool is_number(const string &s);
int turnToVector(string stringInput, vector<double> &v);
void printDistance(double dis);