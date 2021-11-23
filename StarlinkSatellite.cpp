#ifndef STARLINKSATELLITE_CPP
#define STARLINKSATELLITE_CPP
#include "StarlinkSatellite.h"
using namespace std;

    StarlinkSatellite::StarlinkSatellite(){
    }

    void StarlinkSatellite:: NotifyStation(){
        relay->notify(this);
    }

    StarlinkSatellite:: StarlinkSatellite(string communicatesWith, CommunicationRelay* obj):
        PointOfCommunication(){
        this->communicatesWith = communicatesWith;
        this->relay = obj;
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
        StarlinkSatellite* temp =new StarlinkSatellite(communicatesWith,relay);
        return temp;
    }

    StarlinkSatellite* StarlinkSatellite::cloneExact(string communicatesWith, CommunicationRelay* obj){

        StarlinkSatellite* temp = new StarlinkSatellite();
        temp->communicatesWith = this->communicatesWith;
        temp->relay = obj;
        temp->setName(this->getName());

        return temp;
    }

#endif