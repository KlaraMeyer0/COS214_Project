#ifndef FALCONROCKET_H
#define FALCONROCKET_H

using namespace std;

#include "StageEngine.h"

class FalconRocket {
protected:
	StageEngine* stage;
public:
	FalconRocket();
	~FalconRocket();
	void detach();
	void attach(StageEngine*);
	void turnOn();
	void turnOff();
	virtual FalconRocket* clone();
};

#endif