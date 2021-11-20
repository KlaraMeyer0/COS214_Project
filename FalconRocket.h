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
	~FalconRocket();
	void detach(); // Detach the state
	void attach(StageEngine*); // Attach a new state
	void turnOn(); // Turn on the engine
	void turnOff(); // Turn off the engine
	virtual FalconRocket* clone(); // Part of the Protoype DP that is used my the Memento DP to copy the Falon9
	StageEngine* getEngine();
};

#endif