#ifndef SATELLITEMANAGER_H
#define SATELLITEMANAGER_H

using namespace std;

#include "StarlinkSatellite.h"
#include "Satellite.h"
#include <vector>

class SatelliteManager : public Satellite {
public:
	SatelliteManager();
	~SatelliteManager();
    vector<StarlinkSatellite*>* getSatellite(int, int);
    SatelliteManager* clone();
private:
    vector<StarlinkSatellite*>* list;
};

#endif