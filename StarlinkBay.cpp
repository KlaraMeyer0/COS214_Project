#include "StarlinkBay.h"

StarlinkBay::StarlinkBay()
{
    starlink_collection = nullptr;
    falcon9_factory = new Falcon9Factory();
}
StarlinkBay::~StarlinkBay()
{
    delete falcon9_factory;
}

StarlinkCollection *StarlinkBay::getRocketship()
{
    return starlink_collection;
}

//These mehtod must be called in sequence 

void StarlinkBay::setName(string n, BaseStation* BS ,SpaceStation* SS)
{
    starlink_collection = new StarlinkCollection(n,BS,SS);
}

void StarlinkBay::buildRocket()
{
    starlink_collection->attachRocket(falcon9_factory->startFactory());
}

void StarlinkBay::buildBody(){}

void StarlinkBay::addCargo()
{
    int num_B=-1,num_S=-1;
    cout<<"Number of StarlinkSattelites that communicates with the BaseStation: \n";
    cin>>num_B;
    cout<<"Number of StarlinkSattelites that communicates with the SpaceStation: \n";
    cin>>num_S;

    starlink_collection->setNums(num_B,num_S);
    starlink_collection->setSatellites(num_B, num_S);
}