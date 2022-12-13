/*
header for the Distance class.
*/

#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Distance
{
private:
    string type;

    /*
    
    */
    double euclidean(vector<double> vec1, vector<double> vec2, int size);
    double manhattan(vector<double> vec1, vector<double> vec2, int size);
    double chebyshev(vector<double> vec1, vector<double> vec2, int size);
    double canberra(vector<double> vec1, vector<double> vec2, int size);
    double minkowski(vector<double> vec1, vector<double> vec2, int size, double p = 3);

public:
    /*
    Constructor function
    */
    Distance(string type);

    /*
    
    */
    double dis(vector<double> vec1, vector<double> vec2);
    string getType();
    void setType(string newType);
};