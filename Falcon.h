#ifndef FALCON_H
#define FALCON_H

using namespace std;

#include "MerlinEngine.h"

class Falcon {
private:
    MerlinEngine** merlins;
public:
    Falcon();
    ~Falcon();
    void TurnOn();
    void TurnOff();
};

#endif