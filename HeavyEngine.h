#ifndef HeavyENGINE_H
#define HeavyENGINE_H

using namespace std;

#include "Stage1Engine.h"
#include "Stage2Engine.h"
#include "FalconCore.h"
#include "FalconRocket.h"

class HeavyEngine : public Stage1Engine {
private:
	FalconCore** cores; // Array of falcon cores, the engine used in this state
public:
	HeavyEngine();
	~HeavyEngine();
	void TurnOn(FalconRocket*); // Turn on the rocket's engine
	void TurnOff(FalconRocket*); // Turn off the rocket's engine
};

#endif