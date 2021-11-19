#ifndef STARLINKFACTORY_H
#define STARLINKFACTORY_H

using namespace std;

#include "SatelliteFactory.h"
#include "StarlinkSatellite.h"

class StarlinkFactory : public SatelliteFactory {
public:
	StarlinkFactory();
	~StarlinkFactory();
protected:
    Satellite* createSatellite();
};

#endif