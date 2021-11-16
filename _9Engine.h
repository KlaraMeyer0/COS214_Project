#ifndef _9ENGINE_H
#define _9ENGINE_H

using namespace std;

#include "Stage1Engine.h"
#include "FalconCore.h"

class _9Engine {
private:
	FalconCore* core;
public:
	_9Engine();
	~_9Engine();
	virtual void TurnOn();
	virtual void TurnOff();
};

#endif