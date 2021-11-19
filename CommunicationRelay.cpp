#ifndef COMMUNICATIONRELAY_CPP
#define COMMUNICATIONRELAY_CPP
#include "CommunicationRelay.h"
using namespace std;

CommunicationRelay::CommunicationRelay(Station* obj,int numSats ){
    this->RelayTo =obj;
    this->numSats =numSats;
}

CommunicationRelay::~CommunicationRelay(){
    delete RelayTo;
}

void CommunicationRelay:: addSatellite(StarlinkSatellite* obj){
    satellites.push_back(obj);
    SatStatus[obj->getName()]=obj->getStatus();
}

void CommunicationRelay:: notify(StarlinkSatellite* obj){
    SatStatus[obj->getName()]=obj->getStatus();
    RelayTo->updateStatus(obj);
}

#endif