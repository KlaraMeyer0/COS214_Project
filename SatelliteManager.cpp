#ifndef SATELLITEMANAGER_CPP
#define SATELLITEMANAGER_CPP

#include "SatelliteManager.h"

SatelliteManager::SatelliteManager() {} //if you paramaterise constructor edit ManagerFactory.cpp creation of SatelliteManager

SatelliteManager::~SatelliteManager() {}

SatelliteManager *SatelliteManager::clone()
{
    // implement clone --Thank you in advance :p
}

// creates a vector of satelites with num_B satallites communicating with
// BaseStation and num_O sattelites communicating with space station
vector<StarlinkSatellite *> *getSatellite(int num_B, int num_S)
{
    vector<Satellite*> *ptr = new vector<Satellite *>();
    for(int i=0;i<num_B;++i)
        ptr->push_back(new StarlinkSatellite())

}

#endif