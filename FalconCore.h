#ifndef FALCON_H
#define FALCON_H

using namespace std;

#include "Engine.h"
#include "MerlinEngine.h"

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