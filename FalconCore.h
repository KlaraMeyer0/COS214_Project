#ifndef FALCONCORE_H
#define FALCONCORE_H

using namespace std;

#include "Engine.h"
#include "MerlinEngine.h"
#include <iostream>

class FalconCore : public Engine {
private:
	MerlinEngine** merlins;
public:
	FalconCore();
	~FalconCore();
	void TurnOn();
	void TurnOff();
};

#endif