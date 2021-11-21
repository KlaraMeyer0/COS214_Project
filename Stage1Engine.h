#ifndef STAGE1ENGINE_H
#define STAGE1ENGINE_H

using namespace std;

#include "FalconRocket.h"
#include "StageEngine.h"

class Stage1Engine : public StageEngine {
public:
	Stage1Engine();
	virtual ~Stage1Engine();
	virtual void TurnOn(FalconRocket*) = 0; // Turn on the engine
	virtual void TurnOff(FalconRocket*) = 0; // Turn off the engine
	virtual int EngineCount() = 0;//Returns the number of engines
	virtual bool getState() = 0;
};

#endif