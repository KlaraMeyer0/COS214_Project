#ifndef CREWDRAGONBAY_H
#define CREWDRAGONBAY_H

#include "RocketshipBay.h"

class CrewDragonBay : public RocketshipBay {
public:
	CrewDragonBay();
	~CrewDragonBay();
	void getRocketship();
	void buildRocket();
	void buildBody();
	void addCargo();
};

#endif