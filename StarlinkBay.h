#ifndef STARLINKBAY_H
#define STARLINKBAY_H

#include "RocketshipBay.h"
#include "StarlinkCollection.h"
#include "Falcon9Factory.h"

class StarlinkBay : public RocketshipBay
{
public:
	StarlinkBay();
	~StarlinkBay();
	StarlinkCollection *getRocketship();
	void setName(string n, BaseStation* BS ,SpaceStation* SS);
	void buildRocket();
	void buildBody();
	void addCargo();

private:
	StarlinkCollection *starlink_collection;
	RocketFactory *falcon9_factory;

};

#endif