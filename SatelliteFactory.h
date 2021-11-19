#ifndef SATELLITEFACTORY_H
#define SATELLITEFACTORY_H

#include "PointOfCommunication.h"

class SatelliteFactory
{
public:
    SatelliteFactory();
    ~SatelliteFactory();
    PointOfCommunication *startFactory();
protected:
    virtual PointOfCommunication *createSatellite() = 0;
};

#endif