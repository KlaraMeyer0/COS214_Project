#ifndef _9ENGINE_H
#define _9ENGINE_H

using namespace std;

#include "Stage1Engine.h"
#include "Stage2Engine.h"
#include "FalconCore.h"
#include "FalconRocket.h"

class _9Engine : public Stage1Engine {
private:
	FalconCore* core;
public:
	_9Engine();
	~_9Engine();
	void TurnOn(FalconRocket*);
	void TurnOff(FalconRocket*);
};

#endif