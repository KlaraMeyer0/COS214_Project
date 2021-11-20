#include <iostream>

using namespace std;

#include "BaseStation.h"

BaseStation::BaseStation() : Station() {}

BaseStation::~BaseStation() {}

void BaseStation::receiveCargo(Cargo *c,int amount)
{
    if (c->isHuman())
        humans.push_back(c);
    else
    {
        pair<Cargo*,int> p;
        p.first = c;
        p.second = amount;

        equipment.push_back(p);
    }

    cout << c->getName() << " has arrived at the base station." << endl;
}

void BaseStation::receiveCommunication(string s)
{
    cout << "Communication: " << s << " received at base station." << endl;
}

// call receiveCargo from another function that calls the factory for human or equipment respectively
void BaseStation::printEquipment()
{
    for (int i = 0; i < equipment.size(); i++)
        cout << "Index: " << i << " Type: " << equipment.at(i).first->getName() << " Number: " << equipment.at(i).second << endl;
}

void BaseStation::printHumans()
{
    for (int i = 0; i < humans.size(); i++)
        cout << "index: " << i << " Name: " << humans.at(i) << endl;
}

pair<Cargo *, int> *BaseStation::loadCargo(int idx)
{
    return nullptr;
}

Cargo *BaseStation::loadHumans(int idx)
{
    return nullptr;
}
