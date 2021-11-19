#ifndef STARLINKSATELLITE_CPP
#define STARLINKSATELLITE_CPP
#include "StarlinkSatellite.h"
using namespace std;

    StarlinkSatellite:: StarlinkSatellite(string communicatesWith, CommunicationRelay* obj):
        PointOfCommunication(){
        
        this->communicatesWith = communicatesWith;
        relay = obj;
    }

	StarlinkSatellite::~StarlinkSatellite(){
    }
    
    string StarlinkSatellite:: getCommunicatesWith(){
        return communicatesWith;
    }

    StarlinkSatellite* StarlinkSatellite:: clone(){
        return new StarlinkSatellite(communicatesWith,relay);
    }

#endif