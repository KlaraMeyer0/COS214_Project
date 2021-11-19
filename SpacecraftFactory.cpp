#include "SpacecraftFactory.h"

SpacecraftFactory::SpacecraftFactory() {}
SpacecraftFactory::~SpacecraftFactory() {}

Spacecraft *SpacecraftFactory::startFactory()
{
    return createRocket();
}