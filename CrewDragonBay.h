#ifndef CREWDRAGONBAY_H
#define CREWDRAGONBAY_H

using namespace std;

#include "RocketshipBay.h"

class CrewDragonBay : public RocketshipBay {
public:
	CrewDragonBay();
	~CrewDragonBay();
	void getRocketship();
	void buildRocket();
	void buildBody();
	void buildCargo();
};

#endif