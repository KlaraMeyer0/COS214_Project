#ifndef FALCONCORE_H
#define FALCONCORE_H

using namespace std;

#include "Engine.h"
#include "MerlinEngine.h"
#include <iostream>

class FalconCore : public Engine {
private:
	MerlinEngine** merlins; // Array of merlin engines
	const int EngineCount = 9;// Used for testing//Don't remove
public:
	FalconCore();
	virtual ~FalconCore();
	void TurnOn(); // Turn on the engine
	void TurnOff(); // Turn off the engine
	int getCount();// Returns number of engines in core
};

#endif