#include "CrewDragonFactory.h"
#include "CrewDragonSpacecraft.h"
#include <iostream>

CrewDragonFactory::CrewDragonFactory() {}
CrewDragonFactory::~CrewDragonFactory() {}

Spacecraft *CrewDragonFactory::createRocket()
{
    cout << "CrewDragon spacecraft successfully create" << endl;
    return new CrewDragonSpacecraft(75);
}