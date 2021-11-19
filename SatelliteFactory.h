#ifndef SATELLITEFACTORY_H
#define SATELLITEFACTORY_H

#include "Satellite.h"

class SatelliteFactory
{
public:
    SatelliteFactory();
    ~SatelliteFactory();
    Satellite *startFactory();
protected:
    virtual Satellite *createSatellite() = 0;
};

#endif