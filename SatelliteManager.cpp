#ifndef SATELLITEMANAGER_CPP
#define SATELLITEMANAGER_CPP
#include "StarlinkSatellite.h"
#include "Satellite.h"
#include "SatelliteManager.h"
#include <vector>
using namespace std;


SatelliteManager::SatelliteManager(){}
	
SatelliteManager::~SatelliteManager(){}

//creates a vector of satelites with num_B satallites communicating with 
//BaseStation and num_O sattelites communicating with space station
vector<StarlinkSatellite*>* getSatellite(int num_B, int num_S){
    vector<StarlinkSatellite*>* ptr = new vector<StarlinkSatellite*>();
}

class SatelliteManager : public Satellite {
private:
    vector<StarlinkSatellite*> list;
public:

};

#endif