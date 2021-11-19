#include <iostream>

using namespace std;

#include "Station.h"


Station::Station() : next(0) {}

Station::~Station() {}

void Station::add(Station *stat)
{
    if (next)
        next->add(stat);
    else
        next = stat;
}

void Station::receiveCargo(Cargo *c)
{
    if (c != nullptr)
        if (next)
            next->receiveCargo(c);
        else
            cout << "Cargo " << c->getName() << " cannot be delivered."<< endl;
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
