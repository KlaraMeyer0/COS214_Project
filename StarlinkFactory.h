#ifndef STARLINKFACTORY_H
#define STARLINKFACTORY_H

using namespace std;

#include "SatelliteFactory.h"

class StarlinkFactory : public SatelliteFactory {
public:
	StarlinkFactory();
	~StarlinkFactory();
    Satellite* createRocket();
};

#endif