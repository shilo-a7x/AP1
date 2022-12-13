#include "Reader.h"
#include "Classifiable.h"
#include "KNN.h"

int main(int argc, char const *argv[]) {
    Reader reader;
    vector<vector<string>> data(reader.readCSV(argv[2]));
    vector<Classifiable> classified = Classifiable::toVector(data, true);
    return 0;
}
