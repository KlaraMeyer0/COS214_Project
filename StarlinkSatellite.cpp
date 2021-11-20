#ifndef STARLINKSATELLITE_CPP
#define STARLINKSATELLITE_CPP
#include "StarlinkSatellite.h"
using namespace std;

    StarlinkSatellite:: StarlinkSatellite(string communicatesWith, CommunicationRelay* obj):
        PointOfCommunication(){
        
        this->communicatesWith = communicatesWith;
        relay = obj;

        next = NULL;
        previous =NULL;
    }

	StarlinkSatellite::~StarlinkSatellite(){
    }
    
    string StarlinkSatellite:: getCommunicatesWith(){
        return communicatesWith;
    }

    //the names of the StarlinkSatellite will differ
    StarlinkSatellite* StarlinkSatellite:: clone(){
        return new StarlinkSatellite(communicatesWith,relay);
    }

    //Creates exact copy
    StarlinkSatellite* StarlinkSatellite::cloneExact(string communicatesWith, CommunicationRelay* obj){
        StarlinkSatellite* temp = new StarlinkSatellite(communicatesWith,obj);
        temp->communicatesWith =communicatesWith;
        temp->relay =obj;
        this->setName(this->getName());
    }

#endif