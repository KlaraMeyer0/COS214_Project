#ifndef ROCKETSHIPENGINEER_H
#define ROCKETSHIPENGINEER_H

#include "RocketShipBay.h"

class RocketshipEngineer
{
public:
	RocketshipEngineer();
	~RocketshipEngineer();
	void construct(int bay);

private:
	RocketshipBay **rb;
};

#endif