#ifndef MANAGERFACTORY_H
#define MANAGERFACTORY_H

using namespace std;

#include "SatelliteFactory.h"

class ManagerFactory : public SatelliteFactory {
private:
    Satellite* spacecraft;
public:
	ManagerFactory();
	~ManagerFactory();
    Satellite* createRocket();
};

#endif
