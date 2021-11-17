#ifndef STAGE1ENGINE_H
#define STAGE1ENGINE_H

using namespace std;

#include "FalconRocket.h"
#include "StageEngine.h"

class Stage1Engine : public StageEngine {
public:
	Stage1Engine();
	~Stage1Engine();
	virtual void TurnOn(FalconRocket*) = 0;
	virtual void TurnOff(FalconRocket*) = 0;
};

#endif