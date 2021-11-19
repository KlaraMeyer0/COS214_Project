#ifndef SATELLITEITERATOR_H
#define SATELLITEITERATOR_H

using namespace std;

#include "StarlinkSatellite.h"

class SatelliteIterator
{
    public:
        SatelliteIterator(StarlinkSatellite* sat);
        ~SatelliteIterator();
        StarlinkSatellite* next();
        StarlinkSatellite* currentSatellite();
    protected:
        StarlinkSatellite* head;
        StarlinkSatellite* current;
};

#endif