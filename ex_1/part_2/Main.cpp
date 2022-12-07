#include "Main.h"

/*
Calculates the distance between 2 given vectors.
Uses multiple methods of distance calculating.
*/
int main()
{
    string stringInput1, stringInput2;
    vector<double> v1, v2;
    int size, error;

    // getting the vector's parameters from the user as strings.
    getline(cin, stringInput1);
    getline(cin, stringInput2);

    // turns the strings into vectors. makes sure that if failes then error != 0.
    error = turnToVector(stringInput1, v1) + turnToVector(stringInput2, v2);

    // initializing the size to the vector's size
    size = v1.size();

    // if there was an error with the vector initialization or if the vectors are not the same size then terminate.
    if (error || (size != v2.size()))
    {
        cout << "invalid input, goodbye" << endl;
        return 0;
    }

    // calculate each distance and send it to print.
    printDistance(euclidean(v1, v2, size));
    printDistance(manhattan(v1, v2, size));
    printDistance(chebyshev(v1, v2, size));
    printDistance(canberra(v1, v2, size));
    printDistance(minkowski(v1, v2, size, 2));
    return 0;
}

/*
return true if the string given represents a double and false otherwise.
*/
bool is_number(const string &s)
{
    long double ld;

    // return true if the string given to the buffer is a long double and false if not.
    return ((istringstream(s) >> ld >> ws).eof());
}

/*
Converts a string to double vectors.
Checks in the procces whether the input is correct.
If it is, returnes 0;
*/
int turnToVector(string stringInput, vector<double> &v)
{
    // use a buffer to cut the input into words that can be turned into numbers.
    stringstream s(stringInput);
    string token;
    double num;

    // check for every word in the buffer that it represents a number.
    while (s >> token)
    {

        // if the token is not a number return 1 so the error flag will be on.
        if (!is_number(token))
        {
            return 1;
        }

        // tures a string to a double.
        num = strtod(token.c_str(), 0);

        // add the number to the vector.
        v.push_back(num);
    }
    return 0;

} /*
 prints a double.
 if the double is actually an int, print only one digit after the point. else, print 16 digits.
 */
void printDistance(double dis)
{

    // if the floor and the ceiling are the same then it's an int.
    if (floor(dis) == ceil(dis))
    {

        // use precision to print 1 digit after the point.
        fixed(cout);
        cout.precision(1);
    }

    // on any other case it's not an int.
    else
    {

          // use precision to print 16 digits after the point.
        fixed(cout);
        cout.precision(16);
    }

    // print the double.
    cout << dis << endl;
}
