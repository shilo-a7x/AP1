#include "string"

#ifndef DEFAULTIO_H
#define DEFAULTIO_H

using namespace std;

class DefaultIO {
public:
    virtual string read() = 0;

    virtual void write(string) = 0;
};


#endif