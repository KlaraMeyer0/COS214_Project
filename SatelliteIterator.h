#ifndef SATELLITEITERATOR_H
#define SATELLITEITERATOR_H

using namespace std;

#include "StarlinkSatellite.h"
#include "StarlinkCollection.h"

class StarlinkCollection;

class SatelliteIterator
{
    public:
        SatelliteIterator(StarlinkSatellite* sat);
        SatelliteIterator(StarlinkCollection* satCol, StarlinkSatellite* sat);
        ~SatelliteIterator();
        SatelliteIterator next();
        StarlinkSatellite* currentSatellite();
        bool equals(SatelliteIterator*);
    protected:
        StarlinkSatellite* head;
        StarlinkSatellite* current;
};

#endif