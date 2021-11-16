#ifndef HeavyENGINE_H
#define HeavyENGINE_H

using namespace std;

#include "Stage1Engine.h"
#include "FalconCore.h"

class HeavyEngine {
private:
	FalconCore** cores;
public:
	HeavyEngine();
	~HeavyEngine();
	virtual void TurnOn();
	virtual void TurnOff();
};

#endif