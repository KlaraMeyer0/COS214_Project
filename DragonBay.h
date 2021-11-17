#ifndef DRAGONBAY_H
#define DRAGONBAY_H

using namespace std;

#include "RocketshipBay.h"

class DragonBay : public RocketshipBay {
public:
	DragonBay();
	~DragonBay();
	void getRocketship();
	void buildRocket();
	void buildBody();
	void buildCargo();
};

#endif