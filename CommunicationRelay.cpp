#ifndef COMMUNICATIONRELAY_CPP
#define COMMUNICATIONRELAY_CPP
#include "CommunicationRelay.h"
using namespace std;

CommunicationRelay::CommunicationRelay(Station* obj){
    this->RelayTo =obj;
}

CommunicationRelay::~CommunicationRelay(){
    while(satellites.size())
        satellites.pop_back();
    
    RelayTo=NULL;
}

void CommunicationRelay:: addSatellite(StarlinkSatellite* obj){
    SatStatus[obj->getName()]=obj->getStatus();
    satellites.push_back(obj);
    RelayTo->updateStatus(obj);
}

void CommunicationRelay:: notify(StarlinkSatellite* obj){
    SatStatus[obj->getName()]=obj->getStatus();
    RelayTo->updateStatus(obj);
}

void CommunicationRelay:: resolve(StarlinkSatellite* obj){
    for(int i=0; i < satellites.size(); ++i)
        if(obj->getName() == satellites[i]->getName()){
            satellites[i]->setStatus(true);
            notify(obj);
            return;
        }
}

CommunicationRelay* CommunicationRelay:: clone(Station* obj){
    CommunicationRelay* temp = new CommunicationRelay(obj);
    temp->SatStatus = this->SatStatus;
    return temp;
}

map<int ,bool> CommunicationRelay:: getStatStatus(){
    return SatStatus;
}

#endif