#ifndef STARLINKBAY_H
#define STARLINKBAY_H

#include "RocketshipBay.h"
#include "StarlinkCollection.h"
#include "StarlinkFactory.h"
#include "ManagerFactory.h"
#include "Falcon9Factory.h"

class StarlinkBay : public RocketshipBay
{
public:
	StarlinkBay();
	~StarlinkBay();
	StarlinkCollection *getRocketship();
	void setName(string n,Station* s);
	void buildRocket();
	void buildBody();
	void addCargo();

private:
	StarlinkCollection *starlink_collection;
	RocketFactory *falcon9_factory;
	SatelliteFactory *manager_factory;
	SatelliteFactory *starlink_factory;

};

#endif