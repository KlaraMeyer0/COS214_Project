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
}

void SpaceStation::receiveCommunication(string s)
{
    cout << "Communication: " << s << " received at space station." << endl;
}
