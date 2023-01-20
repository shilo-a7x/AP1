#ifndef READER_H
#define READER_H

#include <string>
#include <vector>

using namespace std;
/**
 * @brief This class is in charge of reading files.
 *
 */
class Reader {
private:
    /**
     * @brief Split a string to substrings as elements in vector.
     *
     * @param str the string to be split
     * @param delim a seperator char
     * @return vector<string>
     */
    vector<string> split(const string &str, const char delim);

public:
    /**
     * @brief Read a csv file into a string matrix
     *
     * @param path file path
     * @return vector<vector<string>>
     * @throws std::runtime_error if not in csv format;
     * ios_base::failure if file not found
     */
    vector<vector<string>> readCSV(const string &path);
};

#endif