#ifndef HeavyENGINE_H
#define HeavyENGINE_H

using namespace std;

#include "Stage1Engine.h"
#include "FalconCore.h"
#include "FalconRocket.h"

class HeavyEngine : public Stage1Engine {
private:
	FalconCore** cores;
public:
	HeavyEngine();
	~HeavyEngine();
	virtual void TurnOn(FalconRocket*);
	virtual void TurnOff(FalconRocket*);
};

#endif