#ifndef ROCKETSHIPENGINEER_H
#define ROCKETSHIPENGINEER_H

#include "StarlinkBay.h"
#include "DragonBay.h"
#include "CrewDragonBay.h"

class RocketshipEngineer
{
public:
	RocketshipEngineer();
	~RocketshipEngineer();
	void construct(int bay,string name);

private:
	RocketshipBay **rb;
};

#endif