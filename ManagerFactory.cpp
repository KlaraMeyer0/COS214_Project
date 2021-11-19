#include "ManagerFactory.h"

ManagerFactory::ManagerFactory() {}
ManagerFactory::~ManagerFactory() {}

Satellite *ManagerFactory::createSatellite()
{
    return new SatelliteManager();
}