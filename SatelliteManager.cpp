#ifndef SATELLITEMANAGER_CPP
#define SATELLITEMANAGER_CPP

#include "SatelliteManager.h"

SatelliteManager::SatelliteManager(){
    //Note to self: implement constructor of this
    //CommunicationRelay* relay1 = new 
    //proto1= new StarlinkSatellite("BaseStation")
} 

SatelliteManager::~SatelliteManager() {}

SatelliteManager *SatelliteManager::clone()
{
    // implement clone --Thank you in advance :p
}

// creates a vector of satelites with num_B satallites communicating with
// BaseStation and num_O sattelites communicating with space station
vector<StarlinkSatellite *> *getSatellite(int num_B, int num_S)
{
    vector<StarlinkSatellite*> *ptr = new vector<StarlinkSatellite *>();
    for(int i=0;i<num_B;++i)
        ptr->push_back(new StarlinkSatellite())

}

#endif