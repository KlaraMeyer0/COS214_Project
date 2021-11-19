#include <iostream>

using namespace std;

#include "SpaceStation.h"

SpaceStation::SpaceStation(Cargo *c) : Station(),
{

}

SpaceStation::~SpaceStation()
{

}

void SpaceStation::receiveCargo(Cargo *c)
{
    Station::receiveCargo(c);
}

void SpaceStation::receiveCommunication(string s)
{
    Station::receiveCommunication(s);
}
