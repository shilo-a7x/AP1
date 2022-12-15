#include "Reader.h"
#include "Classifiable.h"
#include "KNN.h"
#include <iostream>
#include <sstream>

int main(int argc, char const *argv[]) {
    Reader reader;
    vector<vector<string>> data;
    if (argc != 4) {
        cout << "Needs 4 valid arguments for KNN!" << endl;
        return 0;
    }
    try {
        int k = atoi(argv[1]);
        if (k <= 0 ) {
            cout << "Invalid k for KNN, must be a positive integer." << endl;
            return 0;
        }
        data = reader.readCSV(argv[2]);
        vector<Classifiable> classified = Classifiable::toVector(data, true);
        if (k > classified.size()) {
            k = classified.size();
        }
        string metric = argv[3];
        KNN knnClassifier(metric, k);
        while (true) {
            string input;
            getline(cin, input);
            istringstream iss(input);
            string component;
            vector<double> v;
            while (iss >> component) {
                v.push_back(stod(component));
            }
            if (v.size() != classified[0].getCoordinates().size()) {
                cout << "Invalid vector dimension, try again!" << endl;
                continue;
            }
            string label = knnClassifier.lunchKNN(classified, v);
            cout << label << endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Invalid input, problem in: " << e.what() << '\n';
    }
    return 0;
}