#include "StandardIO.h"
#include <iostream>

string StandardIO::read() {
    string rs;
    getline(cin, rs);
    return rs;
}

void StandardIO::write(string string) {
    cout << string << endl;
}