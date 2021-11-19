#include "SatelliteFactory.h"

SatelliteFactory::SatelliteFactory() {}
SatelliteFactory::~SatelliteFactory() {}

PointOfCommunication *SatelliteFactory::startFactory()
{
    return createSatellite();
}