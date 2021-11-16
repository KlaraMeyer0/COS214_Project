#ifndef VACUUMENGINE_H
#define VACUUMENGINE_H

using namespace std;

#include "Engine.h"

class VacuumEngine : public Engine {
public:
    VacuumEngine();
    ~VacuumEngine();
    void TurnOn();
    void TurnOff();
};

#endif