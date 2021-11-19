#include "CrewDragonSpacecraft.h"

CrewDragonSpacecraft::CrewDragonSpacecraft(int capacity) : Spacecraft(capacity) {}

CrewDragonSpacecraft::~CrewDragonSpacecraft() {}

Spacecraft *CrewDragonSpacecraft::clone()
{
    return new CrewDragonSpacecraft(getCapacity());
}