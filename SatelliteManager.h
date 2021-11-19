#ifndef SATELLITEMANAGER_H
#define SATELLITEMANAGER_H
#include "StarlinkSatellite.h"
#include "Satellite.h"
#include <vector>
using namespace std;

class SatelliteManager {
public:
	SatelliteManager();
	~SatelliteManager();
    vector<StarlinkSatellite*>* getSatellite(int, int);
    SatelliteManager* clone();
private:
    vector<StarlinkSatellite*>* list;
};

#endif