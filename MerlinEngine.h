#ifndef MERLINENGINE_H
#define MERLINENGINE_H

using namespace std;

#include "Engine.h"
#include <iostream>

class MerlinEngine : public Engine {
public:
	MerlinEngine();
	virtual ~MerlinEngine();
	void TurnOn(); // Turn on the engine
	void TurnOff(); // Turn off the engine
};

#endif