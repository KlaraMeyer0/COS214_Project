#ifndef STARLINKBAY_H
#define STARLINKBAY_H

#include "RocketshipBay.h"

class StarlinkBay : public RocketshipBay {
public:
	StarlinkBay();
	~StarlinkBay();
	void getRocketship();
	void buildRocket();
	void buildBody();
	void addCargo();
};

#endif