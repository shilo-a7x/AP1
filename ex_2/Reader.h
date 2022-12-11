#ifndef READER_H
#define READER_H

#include <vector>
#include <string>

using namespace std;

class Reader {
    private:
        vector<string> split(const string &s, const char c);
    public:
        vector<vector<string>> readCSV(const string &path);
};

#endif