#include <iostream>

using namespace std;

#include "Station.h"

Station::Station(){}

Station::~Station(){
    relayTo = NULL;
}

void Station:: updateStatus(int name,bool status){
    SatStatus[name]=status;
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

void Station::setSatStatus(map<int ,bool> stat){
    SatStatus=stat;
}

void Station::setRelay(CommunicationRelay* obj){
    relayTo = obj;
}

CommunicationRelay* Station:: getRelay(){
    return relayTo;
}