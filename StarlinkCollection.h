#ifndef STARLINKCOLLECTION_H
#define STARLINKCOLLECTION_H

using namespace std;

#include "StarlinkSatellite.h"
#include "SatelliteManager.h"
#include "Rocketship.h"
#include "SatelliteIterator.h"
#include <vector>
#include "BaseStation.h"
#include "SpaceStation.h"

class StarlinkCollection : public Rocketship {
public:
    StarlinkCollection(string name); //Talk to me ~ Xander
	~StarlinkCollection();

    void Launch();

    //Used by the Iterator Design Pattern
    void insert(StarlinkSatellite*);
    StarlinkSatellite* remove();
    SatelliteIterator* begin();
    SatelliteIterator* end();
    StarlinkSatellite* getFirstSat();
    
    StarlinkCollection* clone();

    Station* getBaseStation();
    Station* getSpaseStation();

    virtual int getRocket();
private:
    FalconRocket* rocket;
    int numSatellites;
    SatelliteManager* satelliteManager;
    int num_B;
    int num_S;
    StarlinkSatellite* head;
    Station* BS;
    Station* SS;
};

#endif