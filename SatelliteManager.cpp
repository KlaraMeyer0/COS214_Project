#ifndef SATELLITEMANAGER_CPP
#define SATELLITEMANAGER_CPP

#include "SatelliteManager.h"

SatelliteManager::SatelliteManager(BaseStation* BS ,SpaceStation* SS, StarlinkCollection* SC){

    this->BS =BS;
    this->SS =SS;

    relayBS = new CommunicationRelay(BS);
    relaySS = new CommunicationRelay(SS);

    protoBSSatellite= new StarlinkSatellite("BaseStation",relayBS);
    protoSTSatellite= new StarlinkSatellite("SpaceStation",relaySS);

    this->SC =SC;
    this->SC->setCommunicationRelayBS(relayBS);
    this->SC->setCommunicationRelayBS(relaySS);

    head =NULL;
} 

//Not responsible for any deallication of StarlinkeSatellites handled in StarlinkCollection
SatelliteManager::~SatelliteManager(){
    delete protoBSSatellite;
    delete protoSTSatellite;

    //remove all associations to other classes
    head =NULL;
    relayBS =NULL;
    relaySS =NULL;
    SC =NULL;
    BS =NULL;
    SS =NULL;
}

//Talk To Xander and James for use case
SatelliteManager* SatelliteManager::clone(StarlinkCollection* obj)
{
    BaseStation* BScopy = BS->clone();
    SpaceStation* SScopy = SS->clone();

    SatelliteManager* temp = new SatelliteManager(BScopy ,SScopy ,obj);
    delete temp->relayBS;
    delete temp->relaySS;

    temp->relayBS = relayBS->clone(BScopy);
    temp->relaySS = relaySS->clone(SScopy);
    

    //create a exact copy of the list pointed to by this->head in the StarlinkCollection
    StarlinkSatellite* ptr = head;
    while(ptr != NULL){
        if(ptr->getCommunicatesWith() == "BaseStation")
            obj->insert(ptr->cloneExact("BaseStation",temp->relayBS));
        else
            obj->insert(ptr->cloneExact("SpaceStation",temp->relaySS));
        ptr =ptr->next;
    }

    //set it to the temp->head
    temp->head =obj->getHead();

    return temp;

}

// creates a vector of satelites with num_B satallites communicating with
// BaseStation and num_O sattelites communicating with space station
void SatelliteManager:: setSatellites(int num_B, int num_S)
{
    for(int i=0;i<num_B+num_S;++i)
        if(i<=num_B)
            if(i==0){
                head=protoBSSatellite->clone();
                SC->insert(head);
            }
            else
                SC->insert(protoBSSatellite->clone());           
        else
            SC->insert(protoSTSatellite->clone());

    SC->setHead(head);
}

StarlinkSatellite* SatelliteManager:: getHead(){
    return head;
}

#endif