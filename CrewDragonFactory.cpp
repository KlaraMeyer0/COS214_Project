#include "CrewDragonFactory.h"
#include "CrewDragonSpacecraft.h"
#include <iostream>

CrewDragonFactory::CrewDragonFactory() {}
CrewDragonFactory::~CrewDragonFactory() {}

Spacecraft *CrewDragonFactory::createRocket()
{
    cout << "CrewDragon spacecraft successfully created" << endl;
    return new CrewDragonSpacecraft(75);
}