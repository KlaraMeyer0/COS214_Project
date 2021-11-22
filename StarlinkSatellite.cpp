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
        cout<<"StarlinkSatellite with name : "<<getName()<<" ,communicating with "<<communicatesWith<<" created"<<endl;
    }

	StarlinkSatellite::~StarlinkSatellite(){
        relay = NULL;
        next = NULL;
        previous =NULL;
        cout<<"StarlinkSatellite with name : "<<getName()<<" ,communicating with "<<communicatesWith<<" destroyed"<<endl;
    }
    
    string StarlinkSatellite:: getCommunicatesWith(){
        return communicatesWith;
    }

    StarlinkSatellite* StarlinkSatellite:: clone(){
        cout<<"StarlinkSatellite with name : "<<getName()<<" coppied"<<endl;
        return new StarlinkSatellite(communicatesWith,relay);
    }

    StarlinkSatellite* StarlinkSatellite::cloneExact(string communicatesWith, CommunicationRelay* obj){
        cout<<"StarlinkSatellite with name : "<<getName()<<" coppied"<<endl;
        StarlinkSatellite* temp = new StarlinkSatellite(this->communicatesWith,obj);
        temp->setName(this->getName());

        return temp;
    }

#endif