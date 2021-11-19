#include <iostream>

using namespace std;

#include "BaseStation.h"

BaseStation::BaseStation() : Station() {}

BaseStation::~BaseStation() {}

void BaseStation::receiveCargo(Cargo *c)
{
    if (c->isHuman())
        humans.push_back(c);
    else
        equipment.push_back(c);

    cout << c->getName() << " has arrived at the base station." << endl;
}

void BaseStation::receiveCommunication(string s)
{
    cout << "Communication: " << s << " received at base station." << endl;
}
