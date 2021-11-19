#include "StarlinkFactory.h"

StarlinkFactory::StarlinkFactory() {}
StarlinkFactory::~StarlinkFactory() {}

PointOfCommunication *StarlinkFactory::createSatellite()
{
    return new...;
}