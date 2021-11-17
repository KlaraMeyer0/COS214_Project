#ifndef SATELLITEFACTORY_H
#define SATELLITEFACTORY_H

using namespace std;

#include "Satellite.h"

class SatelliteFactory {
private:
    Satellite* spacecraft;
public:
	SatelliteFactory();
	~SatelliteFactory();
    virtual Satellite* createRocket() = 0;
    Satellite* startFactory();
};

#endif