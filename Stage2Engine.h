#ifndef STAGE2ENGINE_H
#define STAGE2ENGINE_H

using namespace std;

#include "VacuumEngine.h"

class Stage2Engine {
private:
	VacuumEngine* engine;
public:
	Stage2Engine();
	~Stage2Engine();
	virtual void TurnOn();
	virtual void TurnOff();
};

#endif