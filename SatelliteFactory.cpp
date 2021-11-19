#include "SatelliteFactory.h"

SatelliteFactory::SatelliteFactory() {}
SatelliteFactory::~SatelliteFactory() {}

Satellite *SatelliteFactory::startFactory()
{
    return createSatellite();
}