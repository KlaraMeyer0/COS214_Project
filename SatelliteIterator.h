#ifndef SATELLITEITERATOR_H
#define SATELLITEITERATOR_H

using namespace std;

#include "StarlinkSatellite.h"

class SatelliteIterator {
protected:
    StarlinkSatellite* head;
    StarlinkSatellite* current;
public:
	SatelliteIterator(StarlinkSatellite*); //StarLinkCollection first param?
	~SatelliteIterator();
    StarlinkSatellite* next();
    StarlinkSatellite* currentSatellite();
};

#endif