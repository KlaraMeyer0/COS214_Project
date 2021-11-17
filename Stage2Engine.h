#ifndef STAGE2ENGINE_H
#define STAGE2ENGINE_H

using namespace std;

#include "VacuumEngine.h"
#include "FalconRocket.h"
#include "StageEngine.h"

class Stage2Engine : public StageEngine {
private:
	VacuumEngine* engine;
public:
	Stage2Engine();
	~Stage2Engine();
	void TurnOn(FalconRocket*);
	void TurnOff(FalconRocket*);
};

#endif