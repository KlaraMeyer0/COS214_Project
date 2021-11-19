#include "StarlinkBay.h"

StarlinkBay::StarlinkBay()
{
    starlink_collection = nullptr;
    falcon9_factory = new Falcon9Factory();
    manager_factory = new ManagerFactory();
    starlink_factory = new StarlinkFactory();
}
StarlinkBay::~StarlinkBay()
{
    delete falcon9_factory;
    delete manager_factory;
    delete starlink_factory;
}

StarlinkCollection *StarlinkBay::getRocketship()
{
    return starlink_collection;
}

void StarlinkBay::setName(string n)
{
    starlink_collection = new StarlinkCollection(n);
}

void StarlinkBay::buildRocket()
{
    starlink_collection->attachRocket(falcon9_factory->startFactory());
}

void StarlinkBay::buildBody()
{
    starlink_collection->attachManager(manager_factory->startFactory());
}

void StarlinkBay::addCargo()
{
    starlink_factory->startFactory();
}