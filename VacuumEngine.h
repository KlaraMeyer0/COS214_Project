#ifndef VACUUMENGINE_H
#define VACUUMENGINE_H

using namespace std;

#include "Engine.h"
#include <iostream>

class VacuumEngine : public Engine {
public:
	VacuumEngine();
	~VacuumEngine();
	void TurnOn(); // Turn on the engine
	void TurnOff(); // Turn off the engine
};

#endif