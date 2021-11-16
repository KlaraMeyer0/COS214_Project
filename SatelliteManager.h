#ifndef SATELLITEMANAGER_H
#define SATELLITEMANAGER_H

using namespace std;

#include "StarlinkSatellite.h"

class SatelliteManager : public Satellite {
private:
    StarlinkSatellite* list;
public:
	SatelliteManager();
	~SatelliteManager();
    void setStatus();
    StarlinkSatellite** getSatellite(int, int);
};

#endif