#ifndef SATELLITEMANAGER_CPP
#define SATELLITEMANAGER_CPP

#include "SatelliteManager.h"

SatelliteManager::SatelliteManager(Station* BS ,Station* SS, StarlinkCollection* SC){
    relayBS = new CommunicationRelay(BS);
    relaySS = new CommunicationRelay(SS);

    protoBSSatellite= new StarlinkSatellite("BaseStation",relayBS);
    protoSTSatellite= new StarlinkSatellite("SpaceStation",relaySS);

    this->SC =SC;

    head =NULL;
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

    //remove all references to other classes
    head =NULL;
    relayBS =NULL;
    relaySS=NULL;
    SC=NULL;
}

//Talk To Xander and James for use case, CONTINUE HERE
SatelliteManager* SatelliteManager::clone(StarlinkCollection* obj)
{
    SatelliteManager* temp = new SatelliteManager()
    //needs a new connumication realy
    
    //need to attatch all sattelites to communication realy 


    StarlinkSatellite* newHead = head->cloneExact();
    //create a exact copy of the list pointed to by this->head
    StarlinkSatellite* temp = head->next;
    while(temp->next !=NULL){   
        head
    }

    //set it to the temp->head

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
}

StarlinkSatellite* SatelliteManager:: getHead(){
    return head;
}

#endif