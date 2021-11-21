#ifndef STARLINKSATELLITE_CPP
#define STARLINKSATELLITE_CPP
#include "StarlinkSatellite.h"
using namespace std;

    StarlinkSatellite:: StarlinkSatellite(string communicatesWith, CommunicationRelay* obj):
        PointOfCommunication(){
        this->communicatesWith = communicatesWith;
        relay = obj;
        next = nullptr;
        previous =nullptr;
    }

	StarlinkSatellite::~StarlinkSatellite(){
        relay =nullptr;
    }
    
    string StarlinkSatellite:: getCommunicatesWith(){
        return communicatesWith;
    }

    //the names of the StarlinkSatellite will differ
    StarlinkSatellite* StarlinkSatellite:: clone(){
        return new StarlinkSatellite(communicatesWith,relay);
    }

    //Creates exact copy ,with the same name as the calling object
    StarlinkSatellite* StarlinkSatellite::cloneExact(string communicatesWith, CommunicationRelay* obj){
        StarlinkSatellite* temp = new StarlinkSatellite(communicatesWith,obj);
        temp->setName(this->getName());

        return temp;
    }

#endif