#include "StarlinkFactory.h"

StarlinkFactory::StarlinkFactory() {}
StarlinkFactory::~StarlinkFactory() {}

Satellite *StarlinkFactory::createSatellite()
{
    return new...;
}