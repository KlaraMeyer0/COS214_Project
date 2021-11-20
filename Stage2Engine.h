#ifndef STAGE2ENGINE_H
#define STAGE2ENGINE_H

using namespace std;

#include "VacuumEngine.h"
#include "FalconRocket.h"
#include "StageEngine.h"

class Stage2Engine : public StageEngine {
private:
	VacuumEngine* engine; // Variable holding a pointer to the engine
public:
	Stage2Engine();
	~Stage2Engine();
	void TurnOn(FalconRocket*); // Turn on the engine
	void TurnOff(FalconRocket*); // Turn off the engine
};

#endif