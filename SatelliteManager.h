#ifndef SATELLITEMANAGER_H
#define SATELLITEMANAGER_H

using namespace std;

#include "StarlinkSatellite.h"
#include "Satellite.h"
#include <vector>

class SatelliteManager : public Satellite {
private:
    vector<StarlinkSatellite*> list;
public:
	SatelliteManager();
	~SatelliteManager();
    void setStatus();
    vector<StarlinkSatellite*> getSatellite(int, int);
};

#endif