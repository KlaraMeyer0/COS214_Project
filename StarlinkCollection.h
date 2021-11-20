#ifndef STARLINKCOLLECTION_H
#define STARLINKCOLLECTION_H

using namespace std;

#include "StarlinkSatellite.h"
#include "SatelliteManager.h"
#include "Rocketship.h"
#include "FalconRocket.h"
#include "SatelliteIterator.h"
#include <vector>

class StarlinkCollection : public Rocketship {
public:
    StarlinkCollection(string name); //Talk to me ~ Xander
	~StarlinkCollection();
    void Launch();
    SatelliteIterator* begin();
    SatelliteIterator* end();
    Rocketship* clone();
    StarlinkSatellite* getFirstSat();
private:
    FalconRocket* rocket;
    vector<StarlinkSatellite*>* satellites;
    int numSatellites;
    SatelliteManager* satelliteManager;
    int num_G;
    int num_O;
};

#endif