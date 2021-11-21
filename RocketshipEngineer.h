#ifndef ROCKETSHIPENGINEER_H
#define ROCKETSHIPENGINEER_H

#include "StarlinkBay.h"
#include "DragonBay.h"
#include "CrewDragonBay.h"

class RocketshipEngineer
{
public:
	RocketshipEngineer(CrewDragonBay *cd, DragonBay *d, StarlinkBay *s);
	virtual ~RocketshipEngineer();
	void construct(int bay, string name, BaseStation *bs, SpaceStation* ss = nullptr);

private:
	RocketshipBay **rb;
};

#endif