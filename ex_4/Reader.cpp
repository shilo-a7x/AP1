#include "Reader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

vector<vector<string>> Reader::readCSV(const string &path) {
    ifstream inputFile(path);
    if (!inputFile.is_open()) {
        throw ios_base::failure("File not found");
    }
    vector<vector<string>> data;
    ostringstream outStream;
    outStream << inputFile.rdbuf();
    string csv = outStream.str();
    vector<string> lines = split(csv, '\n');
    int csvWidth = split(lines[0], ',').size();
    for (const auto &line : lines) {
        vector<string> row = split(line, ',');
        int rowLen = row.size();
        // all rows must have same number of fields
        if (rowLen != csvWidth) {
            throw runtime_error("File is not in valid csv format");
        }
        if (!row.empty()) {
            data.push_back(row);
        }
    }
    return data;
}

string Reader::readToString(const string &path) {
    ifstream inputFile(path);
    if (!inputFile.is_open()) {
        throw ios_base::failure("File not found");
    }
    ostringstream outStream;
    outStream << inputFile.rdbuf();
    return outStream.str();
}

vector<string> Reader::split(const string &str, const char delim) {
    istringstream ss(str);
    string cell;
    vector<string> vec;
    while (getline(ss, cell, delim)) {
        vec.push_back(cell);
    }
    return vec;
}