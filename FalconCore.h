#ifndef FALCONCORE_H
#define FALCONCORE_H

using namespace std;

#include "Engine.h"
#include "MerlinEngine.h"
#include <iostream>

class FalconCore : public Engine {
private:
	MerlinEngine** merlins; // Array of merlin engines
public:
	FalconCore();
	~FalconCore();
	void TurnOn(); // Turn on the engine
	void TurnOff(); // Turn off the engine
};

#endif