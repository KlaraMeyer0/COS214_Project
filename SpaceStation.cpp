#include <iostream>

using namespace std;

#include "SpaceStation.h"

SpaceStation::SpaceStation() : Station()
{
    name = "Space Station";
}

SpaceStation::~SpaceStation() {}

void SpaceStation::receiveCargo(Cargo *c,int amount)
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

    cout << c->getName() << " has arrived at the space station." << endl;
}

void SpaceStation::receiveCommunication(string s)
{
    cout << "Communication: " << s << " received at space station." << endl;
}

void SpaceStation::printEquipment()
{
    for (int i = 0; i < equipment.size(); i++)
        cout << "Index: " << i << " Type: " << equipment.at(i).first->getName() << " Number: " << equipment.at(i).second << endl;
}

void SpaceStation::printHumans()
{
    for (int i = 0; i < humans.size(); i++)
        cout << "index: " << i << " Name: " << humans.at(i) << endl;
}

pair<Cargo *, int> *SpaceStation::loadCargo(int idx, int num)
{
    pair<Cargo*, int> * p;
    p->first = equipment.at(idx).first;
    p->second = equipment.at(idx).second;
    equipment.erase(equipment.begin() + idx);

    return p;
}

Cargo *SpaceStation::loadHumans(int idx)
{
    Cargo* h = humans.at(idx);
    humans.erase(humans.begin() + idx);
    return h;
}
