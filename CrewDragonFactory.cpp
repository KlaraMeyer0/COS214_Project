#include "CrewDragonFactory.h"
#include "CrewDragonSpacecraft.h"

CrewDragonFactory::CrewDragonFactory() {}
CrewDragonFactory::~CrewDragonFactory() {}

Spacecraft *CrewDragonFactory::createRocket()
{
    return new CrewDragonSpacecraft();
}