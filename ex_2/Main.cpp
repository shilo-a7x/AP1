#include "Distance.h"
#include "Classifiable.h"
#include "KNN.h"
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int i;
    vector<double> v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
    if (true)
    {
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v2.push_back(5);
        v2.push_back(10);
        v2.push_back(15);
        v2.push_back(20);
        v3.push_back(7);
        v3.push_back(3);
        v3.push_back(9);
        v3.push_back(0);
        v4.push_back(1);
        v4.push_back(1);
        v4.push_back(1);
        v4.push_back(1);
        v5.push_back(0);
        v5.push_back(0);
        v5.push_back(0);
        v5.push_back(0);
        v6.push_back(10);
        v6.push_back(20);
        v6.push_back(30);
        v6.push_back(40);
        v7.push_back(0.2);
        v7.push_back(0.1);
        v7.push_back(0.5);
        v7.push_back(0.3);
        v8.push_back(7);
        v8.push_back(8);
        v8.push_back(11);
        v8.push_back(14);
        v9.push_back(9);
        v9.push_back(7);
        v9.push_back(5);
        v9.push_back(3);
        v10.push_back(100);
        v10.push_back(1000);
        v10.push_back(100);
        v10.push_back(1000);
    }
    if (1>0){
        Classifiable c1 = Classifiable(v1,"yes");
        c2,c3,c4,c5,c6,c7,c8,c9,c10
    }
}

// #include "Reader.h"
// #include "Classifiable.h"
// #include "KNN.h"
// #include <iostream>

// int main(int argc, char const *argv[]) {
//     Reader reader;
//     vector<vector<string>> data;
//     if (argc != 4) {
//         cout << "Needs 4 valid arguments for KNN!" << endl;
//         return 0;
//     }
//     try {
//         data = reader.readCSV(argv[2]);
//     } catch (exception &e) {

//     }
//     vector<Classifiable> classified = Classifiable::toVector(data, true);
//     return 0;
// }
