#ifndef SATELLITEMANAGER_CPP
#define SATELLITEMANAGER_CPP

#include "SatelliteManager.h"

SatelliteManager::SatelliteManager(BaseStation* BS ,SpaceStation* SS, StarlinkCollection* SC){

    this->BS =BS;
    this->SS =SS;

    relayBS = new CommunicationRelay(BS);
    relaySS = new CommunicationRelay(SS);

    BS->attachRelay(relayBS);
    SS->attachRelay(relaySS);

    cout<<"\nCreating protoBSSatellite and protoSTSatellite\n";
    protoBSSatellite= new StarlinkSatellite("BaseStation",relayBS);
    protoSTSatellite= new StarlinkSatellite("SpaceStation",relaySS);
    cout<<"Done creating protoBSSatellite and protoSTSatellite\n\n";

    this->SC =SC;
    this->SC->setCommunicationRelayBS(relayBS);
    this->SC->setCommunicationRelayBS(relaySS);

    head =NULL;
} 

SatelliteManager::~SatelliteManager(){
    delete protoBSSatellite;
    delete protoSTSatellite;

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
    
    StarlinkSatellite* ptr =head;
    StarlinkSatellite* tempSat =NULL;
    while(ptr != NULL){
        if(ptr->getCommunicatesWith() == "BaseStation"){
            tempSat=ptr->cloneExact("BaseStation",temp->relayBS);
            objcopy->insert(tempSat);
            relayBS->addSatellite(tempSat);
        }
        else{
            tempSat=ptr->cloneExact("SpaceStation",temp->relaySS);
            objcopy->insert(ptr->cloneExact("SpaceStation",temp->relaySS));
            relaySS->addSatellite(tempSat);
        }
        ptr =ptr->next;
    }

    temp->head =objcopy->getFirstSat();

    return temp;

}

void SatelliteManager:: setSatellites(int num_B, int num_S){

    StarlinkSatellite* tempSat=NULL;
    for(int i=0;i<num_B+num_S;++i)
        if(i<num_B)
            if(i==0){
                head=protoBSSatellite->clone();
                SC->insert(head);
                relayBS->addSatellite(head);
                SC->setHead(head);
            }
            else{
                tempSat = protoBSSatellite->clone();
                SC->insert(tempSat); 
                relayBS->addSatellite(tempSat);          
            }
        else{
            tempSat = protoSTSatellite->clone();
            SC->insert(tempSat);
            relaySS->addSatellite(tempSat);
        }

    SC->setHead(head);
}

StarlinkSatellite* SatelliteManager:: getHead(){
    return head;
}


BaseStation* SatelliteManager:: getBaseStation(){
    return BS;
}

SpaceStation* SatelliteManager:: getSpaceStation(){
    return SS;
}


#endif