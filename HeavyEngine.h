#ifndef HeavyENGINE_H
#define HeavyENGINE_H

using namespace std;

#include "Stage1Engine.h"
#include "Stage2Engine.h"
#include "FalconCore.h"
#include "FalconRocket.h"

class HeavyEngine : public Stage1Engine {
private:
	FalconCore** cores;
public:
	HeavyEngine();
	~HeavyEngine();
	void TurnOn(FalconRocket*);
	void TurnOff(FalconRocket*);
};

#endif