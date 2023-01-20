#include "DefaultIO.h"

#ifndef STANDARDIO_H
#define STANDARDIO_H

using namespace std;

class StandardIO : public DefaultIO {
public:
    void write(string string) override;

    string read() override;
};


#endif