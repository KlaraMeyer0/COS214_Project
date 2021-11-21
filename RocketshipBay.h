#ifndef ROCKETSHIPBAY_H
#define ROCKETSHIPBAY_H

using namespace std;
#include <string>
#include "BaseStation.h"
#include "SpaceStation.h"

class RocketshipBay
{
public:
	virtual void setName(string n, BaseStation *BS, SpaceStation *SS = nullptr) = 0;
	virtual void buildRocket() = 0;
	virtual void buildBody() = 0;
	virtual void addCargo() = 0;
};

#endif