#include "ManagerFactory.h"

ManagerFactory::ManagerFactory() {}
ManagerFactory::~ManagerFactory() {}

PointOfCommunication *ManagerFactory::createSatellite()
{
    return new SatelliteManager();
}