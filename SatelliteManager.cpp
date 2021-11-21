#ifndef SATELLITEMANAGER_CPP
#define SATELLITEMANAGER_CPP

#include "SatelliteManager.h"

SatelliteManager::SatelliteManager(BaseStation* BS ,SpaceStation* SS, StarlinkCollection* SC){

    this->BS =BS;
    this->SS =SS;

    relayBS = new CommunicationRelay(BS);
    relaySS = new CommunicationRelay(SS);

    BS->attatchRelay(relayBS);
    SS->attatchRelay(relaySS);

    protoBSSatellite= new StarlinkSatellite("BaseStation",relayBS);
    protoSTSatellite= new StarlinkSatellite("SpaceStation",relaySS);

    this->SC =SC;
    this->SC->setCommunicationRelayBS(relayBS);
    this->SC->setCommunicationRelayBS(relaySS);

    head =NULL;
} 

//Not responsible for any deallocation of StarlinkSatellites handled in StarlinkCollection
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

//Luca->Xander&James
SatelliteManager* SatelliteManager::clone(StarlinkCollection* objcopy,BaseStation* BScopy ,SpaceStation* SScopy)
{
    SatelliteManager* temp = new SatelliteManager(BScopy ,SScopy ,objcopy);
    delete temp->relayBS;
    delete temp->relaySS;

    temp->relayBS = relayBS->clone(BScopy);
    temp->relaySS = relaySS->clone(SScopy);
    

    //create a exact copy of the list pointed to by this->head in the StarlinkCollection
    StarlinkSatellite* ptr = head;
    while(ptr != NULL){
        if(ptr->getCommunicatesWith() == "BaseStation")
            objcopy->insert(ptr->cloneExact("BaseStation",temp->relayBS));
        else
            objcopy->insert(ptr->cloneExact("SpaceStation",temp->relaySS));
        ptr =ptr->next;
    }

    temp->head =objcopy->getFirstSat();

    return temp;

}

// creates a vector of satellites with num_B satellites communicating with
// BaseStation and num_O satellites communicating with space station
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