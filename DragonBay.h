#ifndef DRAGONBAY_H
#define DRAGONBAY_H

#include "RocketshipBay.h"
#include "DragonRocketship.h"
#include "DragonFactory.h"
#include "CargoFactory.h"
#include "RocketFactory.h"

class DragonBay : public RocketshipBay
{
public:
	DragonBay();
	~DragonBay();
	DragonRocketship *getRocketship();
	void buildRocket();
	void buildBody();
	void addCargo();
};

#endif