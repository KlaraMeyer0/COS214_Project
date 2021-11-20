#ifndef SATELLITEMANAGER_CPP
#define SATELLITEMANAGER_CPP

#include "SatelliteManager.h"

SatelliteManager::SatelliteManager(Station* BS ,Station* SS){
    relayBS = new CommunicationRelay(BS);
    relaySS = new CommunicationRelay(SS);

    protoBSSatellite= new StarlinkSatellite("BaseStation",relayBS);
    protoSTSatellite= new StarlinkSatellite("SpaceStation",relaySS);
} 

CommunicationRelay* SatelliteManager:: getCommunicationRelayBS(){
    return relayBS;
}

CommunicationRelay* SatelliteManager:: getCommunicationRelaySS(){
    return relaySS;
}

//Not responsible for any deallication of StarlinkeSatellites handled in StarlinkCollection
SatelliteManager::~SatelliteManager(){
    delete protoBSSatellite;
    delete protoSTSatellite;
}

//Talk To Xander and James for use case
SatelliteManager* SatelliteManager::clone()
{
    SatelliteManager* temp = new SatelliteManager(Station* BS,Station* SS);
}

// creates a vector of satelites with num_B satallites communicating with
// BaseStation and num_O sattelites communicating with space station
vector<StarlinkSatellite *>* SatelliteManager:: getSatellite(int num_B, int num_S)
{
    vector<StarlinkSatellite*> *ptr = new vector<StarlinkSatellite *>();
    for(int i=0;i<num_B+num_S;++i)
        if(i<=num_B)
            ptr->push_back(protoBSSatellite->clone());
        else
            ptr->push_back(protoSTSatellite->clone());

    return ptr;
}

#endif