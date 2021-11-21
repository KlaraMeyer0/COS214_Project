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
        relay = NULL;
        next = NULL;
        previous =NULL;
    }
    
    string StarlinkSatellite:: getCommunicatesWith(){
        return communicatesWith;
    }

    StarlinkSatellite* StarlinkSatellite:: clone(){
        return new StarlinkSatellite(communicatesWith,relay);
    }

    StarlinkSatellite* StarlinkSatellite::cloneExact(string communicatesWith, CommunicationRelay* obj){
        StarlinkSatellite* temp = new StarlinkSatellite(this->communicatesWith,obj);
        temp->setName(this->getName());

        return temp;
    }

#endif