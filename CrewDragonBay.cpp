#include "CrewDragonBay.h"

CrewDragonBay::CrewDragonBay()
{
    crew_dragon = nullptr;
    falconheavy_factory = new FalconHeavyFactory();
    crewdragon_factory = new CrewDragonFactory();
}
CrewDragonBay::~CrewDragonBay()
{
    delete falconheavy_factory;
    delete crewdragon_factory;
}

CrewDragonRocketship *CrewDragonBay::getRocketship()
{
    return crew_dragon;
}

void CrewDragonBay::setName(string n)
{
    crew_dragon = new CrewDragonRocketship(n);
}

void CrewDragonBay::buildRocket()
{
    crew_dragon->attachRocket(falconheavy_factory->startFactory());
}

void CrewDragonBay::buildBody()
{
    crew_dragon->attachSpacecraft(crewdragon_factory->startFactory());
}

void CrewDragonBay::addCargo()
{
    // use Base station to load cargo ;)
    cout << "LOAD FROM BASE STATION" << endl;
}