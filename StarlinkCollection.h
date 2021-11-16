#ifndef STARLINKCOLLECTION_H
#define STARLINKCOLLECTION_H

using namespace std;

#include "StarlinkSatellite.h"
#include "SatelitteManager.h"
#include "Rocketship.h"
#include "FalconRocket.h"

class StarlinkCollection : public Rocketship {
private:
    FalconRocket* rocket;
    StarlinkSatellite* satellites;
    int numSatellites;
    SatelitteManager* satelitteCreator;
    int num_G;
    int num_O;
public:
	StarlinkCollection(int, int, int);
	~StarlinkCollection();
    void Launch();
    SatelliteIterator* begin();
    SatelliteIterator* end();
};

#endif