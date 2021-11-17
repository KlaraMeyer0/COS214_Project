#ifndef STAGEENGINE_H
#define STAGEENGINE_H

using namespace std;

#include "FalconRocket.h"

class StageEngine {
public:
	StageEngine();
	~StageEngine();
	virtual void TurnOn(FalconRocket*) = 0;
	virtual void TurnOff(FalconRocket*) = 0;
};

#endif