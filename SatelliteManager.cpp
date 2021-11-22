#ifndef SATELLITEMANAGER_CPP
#define SATELLITEMANAGER_CPP

#include "SatelliteManager.h"

SatelliteManager:: SatelliteManager(){
}

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
    this->SC->setCommunicationRelaySS(relaySS);

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
    SatelliteManager* temp = new SatelliteManager();
    temp->BS=BScopy;
    temp->SS=SScopy;

    //relays already cloned in StarlinkCollection must be set
    temp->relayBS = BScopy->getRelay();
    temp->relaySS = SScopy->getRelay();

    //setting prototypical instances of temp
    temp->protoBSSatellite= this->protoBSSatellite->cloneExact("BaseStation",temp->relayBS);
    temp->protoSTSatellite= this->protoSTSatellite->cloneExact("SpaceStation",temp->relaySS);

    temp->SC = objcopy;

    StarlinkSatellite* tempSat =NULL;
    StarlinkSatellite* thistempSat =NULL;

    SatelliteIterator* it =NULL;
    for(it= this->SC->begin();!it->equals(this->SC->end()) ;it->next()){
        thistempSat =it->currentSatellite();
        if(thistempSat->getCommunicatesWith() == "BaseStation"){
            tempSat=thistempSat->cloneExact("BaseStation",temp->relayBS);
            objcopy->insert(tempSat);
            temp->relayBS->addSatellite(tempSat);
        }
        else{
            tempSat=thistempSat->cloneExact("SpaceStation",temp->relaySS);
            objcopy->insert(tempSat);
            temp->relaySS->addSatellite(tempSat);
        }
    }
    //below part is nesscesary due to way iterator onstructed
    thistempSat =it->currentSatellite();
    if(thistempSat->getCommunicatesWith() == "BaseStation"){
        tempSat=thistempSat->cloneExact("BaseStation",temp->relayBS);
        objcopy->insert(tempSat);
        temp->relayBS->addSatellite(tempSat);
    }
    else{
        tempSat=thistempSat->cloneExact("SpaceStation",temp->relaySS);
        objcopy->insert(tempSat);
        temp->relaySS->addSatellite(tempSat);
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