#include <iostream>

using namespace std;

#include "Station.h"

Station::Station() : next(0) {}

Station::~Station(){
    relayTo = NULL;
}

void Station::add(Station *stat)
{
    if (next)
        next->add(stat);
    else
        next = stat;
}

void Station::receiveCommunication(string com)
{
    if (!com.empty())
        if (next)
            next->receiveCommunication(com);
        else
            cout << "Communication did not reach the station." << endl;
}

void Station:: updateStatus(StarlinkSatellite* obj){
    SatStatus[obj->getName()]=obj->getStatus();
}

void Station:: resolve(StarlinkSatellite* obj){
    relayTo->resolve(obj);
}

void Station:: attachRelay(CommunicationRelay* obj){
    relayTo = obj;
}

string Station:: getName(){
    return name;
}

map<int ,bool> Station:: getSatStatus(){
    return SatStatus;
}

void Station::setName(string n)
{
    name = n;
}
