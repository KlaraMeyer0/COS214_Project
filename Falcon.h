#ifndef FALCON_H
#define FALCON_H

using namespace std;

#include "Engine.h"
#include "MerlinEngine.h"

class Falcon : public Engine {
private:
    MerlinEngine** merlins;
public:
    Falcon();
    ~Falcon();
    void TurnOn();
    void TurnOff();
};

#endif