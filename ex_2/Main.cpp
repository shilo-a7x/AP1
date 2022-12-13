#include "Reader.h"
#include "Classifiable.h"
#include "KNN.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    Reader reader;
    vector<vector<string>> data;
    if (argc != 4) {
        cout << "Needs 4 valid arguments for KNN!" << endl;
        return 0;
    }
    try {
        data = reader.readCSV(argv[2]);
    } catch (exception &e) {
        
    }
    vector<Classifiable> classified = Classifiable::toVector(data, true);
    return 0;
}
