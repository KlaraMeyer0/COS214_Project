#ifndef DRAGONBAY_H
#define DRAGONBAY_H

#include "RocketshipBay.h"
#include "DragonRocketship.h"
#include "DragonFactory.h"
#include "FalconHeavyFactory.h"

class DragonBay : public RocketshipBay
{
public:
	DragonBay();
	~DragonBay();
	DragonRocketship *getRocketship();
	void setName(string n, BaseStation *bs, SpaceStation *sp = nullptr);
	void buildRocket();
	void buildBody();
	void addCargo();

private:
	DragonRocketship *dragon;
	RocketFactory *falconheavy_factory;
	SpacecraftFactory *dragon_factory;
};

#endif