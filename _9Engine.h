#ifndef _9ENGINE_H
#define _9ENGINE_H

using namespace std;

#include "Stage1Engine.h"
#include "Stage2Engine.h"
#include "FalconCore.h"
#include "FalconRocket.h"

class _9Engine : public Stage1Engine {
private:
	FalconCore* core; // Pointer to FalconCore engine
public:
	_9Engine();
	virtual ~_9Engine();
	void TurnOn(FalconRocket*); // Turns on the engine
	void TurnOff(FalconRocket*); // Turns off the engine
	virtual int EngineCount();//Returns the number of engines
	virtual bool getState();// Get state of engines
};

#endif