#ifndef COMMUNICATIONRELAY_CPP
#define COMMUNICATIONRELAY_CPP
#include "CommunicationRelay.h"
using namespace std;

CommunicationRelay::CommunicationRelay(Station* obj){
    cout<<"CommunicationRelay communicating with: "<<obj->getName()<<" created"<<endl;
    this->RelayTo =obj;
}

CommunicationRelay::~CommunicationRelay(){
    cout<<"CommunicationRelay destoryed"<<endl;
    while(satellites.size())
        satellites.pop_back();
    
    RelayTo=NULL;
}

void CommunicationRelay:: addSatellite(StarlinkSatellite* obj){
    cout<<"StarlinkSatellite with name: "<<obj->getName()<<" attached to CommunicationRelay."<<endl;
    SatStatus[obj->getName()]=obj->getStatus();
    satellites.push_back(obj);
    RelayTo->updateStatus(obj);
}

void CommunicationRelay:: notify(StarlinkSatellite* obj){
    cout<<"StarlinkSatellite with name: "<<obj->getName()<<" notified Station with name: "
    << RelayTo->getName()<< endl;
    SatStatus[obj->getName()]=obj->getStatus();
    RelayTo->updateStatus(obj);
}

void CommunicationRelay:: resolve(StarlinkSatellite* obj){
    cout<<"Station with name: "<< RelayTo->getName() <<"resolved the error of "<<
    "StarlinkSatellite with name: "<<obj->getName()<<endl;
    for(int i=0; i < satellites.size(); ++i)
        if(obj->getName() == satellites[i]->getName()){
            satellites[i]->setStatus(true);
            notify(obj);
            return;
        }
}

CommunicationRelay* CommunicationRelay:: clone(Station* obj){
    cout<<"CommunicationRelay cloned"<<endl;
    CommunicationRelay* temp = new CommunicationRelay(obj);
    temp->SatStatus = this->SatStatus;
    return temp;
}

map<int ,bool> CommunicationRelay:: getStatStatus(){
    return SatStatus;
}

#endif