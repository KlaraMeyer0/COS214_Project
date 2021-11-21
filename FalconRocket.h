#ifndef FALCONROCKET_H
#define FALCONROCKET_H

using namespace std;

#include "StageEngine.h"
class StageEngine;

class FalconRocket {
protected:
	StageEngine* stage; // Variable storing the state of the rocket
public:
	FalconRocket();
	virtual ~FalconRocket();
	void detach(); // Detach the state
	void attach(StageEngine*); // Attach a new state
	void turnOn(); // Turn on the engine
	void turnOff(); // Turn off the engine
	virtual FalconRocket* clone() = 0; // Part of the Protoype DP that is used by the Memento DP to copy the Falon9
	StageEngine* getEngine();// Returns the attached engine
	bool getState();// Returns if engines are currently on
};

#endif