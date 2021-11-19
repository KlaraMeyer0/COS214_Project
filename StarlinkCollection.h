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
private:
    FalconRocket* rocket;
    vector<Satellite*> satellites;
    int numSatellites;
    SatelliteManager* satelitteCreator;
    int num_G;
    int num_O;
public:
	StarlinkCollection(int, int, int);
    StarlinkCollection(string name); //Talk to me ~ Xander
	~StarlinkCollection();
    void Launch();
    SatelliteIterator* begin();
    SatelliteIterator* end();
    Rocketship* clone();
};

#endif