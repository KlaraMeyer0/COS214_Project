#ifndef COMMUNICATIONRELAY_CPP
#define COMMUNICATIONRELAY_CPP
#include "CommunicationRelay.h"
using namespace std;

CommunicationRelay::CommunicationRelay(Station* obj){
    this->RelayTo =obj;
}

CommunicationRelay::~CommunicationRelay(){
    while(sattelites.size())
        sattelites.pop_back();
}

void CommunicationRelay:: addSatellite(StarlinkSatellite* obj){
    SatStatus[obj->getName()]=obj->getStatus();
}

void CommunicationRelay:: notify(StarlinkSatellite* obj){
    SatStatus[obj->getName()]=obj->getStatus();
    RelayTo->updateStatus(obj);
}

void CommunicationRelay:: reslove(StarlinkSatellite* obj){
    for(int i=0;i<sattelites.size();++i)
        if(obj->getName() == sattelites[i]->getName()){
            sattelites[i]->setStauts(true);
            return;
        }
}

//obj is a new Station ,not the same station
CommunicationRelay* CommunicationRelay:: clone(Station* obj){
    CommunicationRelay* temp = new CommunicationRelay(obj);
    temp->numSats = numSats;
    this->SatStatus = SatStatus;
    return temp;
}

#endif