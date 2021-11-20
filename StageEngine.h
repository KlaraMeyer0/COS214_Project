#ifndef STAGEENGINE_H
#define STAGEENGINE_H

using namespace std;

#include "FalconRocket.h"

class StageEngine {
public:
	StageEngine();
	~StageEngine();
	virtual void TurnOn(FalconRocket*) = 0; // Turn on the engine
	virtual void TurnOff(FalconRocket*) = 0; // Turn off the engine
};

#endif