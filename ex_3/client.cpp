#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief
 *
 * @param argc expected 3 arguments
 * @param argv expected "client.out ip port"
 * @return int
 */
int main(int argc, char const *argv[]) {
    if (argc != 3) {
        cout << "Needs 3 valid arguments to run client" << endl;
        return 0;
    }
    try {
        int k = atoi(argv[1]);
        if (k <= 0) {
            cout << "Invalid k for KNN, must be a positive integer." << endl;
            return 0;
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
    } catch (const std::exception &e) {
        std::cerr << "Invalid input, problem in: " << e.what() << '\n';
    }
    return 0;
}