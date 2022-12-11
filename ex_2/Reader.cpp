#include "Reader.h"
#include <fstream>
#include <sstream>
#include <iostream>


vector<vector<string>> Reader::readCSV(const string &path) {
    ifstream inputFile(path);
    if (!inputFile.is_open()) {
        throw ios_base::failure("File not found");
    }
    vector<vector<string>> data;
    stringstream outStream;
    outStream << inputFile.rdbuf();
    string csv = outStream.str();
    for (const auto &line : split(csv, '\n')) {
        vector<string> row = split(line, ',');
        if (!row.empty()) {
            data.push_back(row);
        }
    }
    return data;
}

vector<string> Reader::split(const string &str, const char delim) {
    stringstream ss(str);
    string cell;
    vector<string> vec;
    while (getline(ss, cell, delim)) {
        vec.push_back(cell);
    }
    return vec;
}