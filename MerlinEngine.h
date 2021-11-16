#ifndef MERLINENGINE_H
#define MERLINENGINE_H

using namespace std;

#include "Engine.h"

class MerlinEngine : public Engine {
public:
    MerlinEngine();
    ~MerlinEngine();
    void TurnOn();
    void TurnOff();
};

#endif