#ifndef CREWDRAGONBAY_H
#define CREWDRAGONBAY_H

#include "RocketshipBay.h"
#include "CrewDragonRocketship.h"
#include "CrewDragonFactory.h"
#include "FalconHeavyFactory.h"

class CrewDragonBay : public RocketshipBay
{
public:
	CrewDragonBay();
	~CrewDragonBay();
	CrewDragonRocketship *getRocketship();
	void setName(string n);
	void buildRocket();
	void buildBody();
	void addCargo();

private:
	CrewDragonRocketship *crew_dragon;
	SpacecraftFactory *crewdragon_factory;
	RocketFactory *falconheavy_factory;
};

#endif