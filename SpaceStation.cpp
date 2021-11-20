#include <iostream>

using namespace std;

#include "SpaceStation.h"

SpaceStation::SpaceStation() : Station() {}

SpaceStation::~SpaceStation() {}

void SpaceStation::receiveCargo(Cargo *c)
{
    if (c->isHuman())
        humans.push_back(c);
    else
        equipment.push_back(c);

    cout << c->getName() << " has arrived at the space station." << endl;
}

void SpaceStation::receiveCommunication(string s)
{
    cout << "Communication: " << s << " received at space station." << endl;
}

void SpaceStation::printEquipment()
{

}

void SpaceStation::printHumans()
{

}

pair<Cargo *, int> *SpaceStation::loadCargo(int idx)
{
    return nullptr;
}

Cargo *SpaceStation::loadHumans(int idx)
{
    return nullptr;
}
