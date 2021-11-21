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
    void StarlinkBay::setName(string n, BaseStation* BS ,SpaceStation* SS=0); 
	void buildRocket();
	void buildBody();
	void addCargo();

private:
	StarlinkCollection *starlink_collection;
	RocketFactory *falcon9_factory;
};

#endif