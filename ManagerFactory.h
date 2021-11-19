#ifndef MANAGERFACTORY_H
#define MANAGERFACTORY_H

#include "SatelliteFactory.h"
#include "SatelliteManager.h"

class ManagerFactory : public SatelliteFactory {
public:
	ManagerFactory();
	~ManagerFactory();
protected:
    Satellite* createSatellite();
};

#endif
