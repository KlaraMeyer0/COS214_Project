#include <iostream>

using namespace std;

#include "SpaceStation.h"

SpaceStation::SpaceStation() : Station()
{
    setName("Space-RXKJL-68348");

    handler = new HumanHandler();
    handler->add(new EquipmentHandler());

    cout << "Space station " << getName() << " has been created." << endl;
}

SpaceStation::~SpaceStation()
{
    delete handler;
}

void SpaceStation::receiveCargo(Cargo *c)
{
    handler->handleCargo(c, this);
}

void SpaceStation::receiveCommunication(string s)
{
    cout << "Communication: " << s << " received at space station." << endl;
}

void SpaceStation::printEquipment()
{
    if (equipment.empty())
        cout << "There is no equipment at the station." << endl;
    else
        for (int i = 0; i < equipment.size(); i++)
            cout << "Index: " << (i + 1) << " Type: " << equipment.at(i).first->getName() << " Number: "
                 << equipment.at(i).second << endl;
}

void SpaceStation::printHumans()
{
    if (humans.empty())
        cout << "There are no humans at the station." << endl;
    else
        for (int i = 0; i < humans.size(); i++)
            cout << "index: " << (i + 1) << " Name: " << humans.at(i)->getName() << endl;
}

pair<Cargo *, int> SpaceStation::loadEquipment(int idx, int num)
{
     pair<Cargo *, int> p;
    p = make_pair(equipment.at(0).first, p.second = num);

    if (idx > equipment.size() - 1)
    {
        p.second = -1;
        return p;
    }

    p.first = equipment.at(idx).first;

    if (equipment.at(idx).second > num)
    {
        equipment.at(idx).second -= num;
    } else if (equipment.at(idx).second <= num)
    {
        p.second = equipment.at(idx).second;
        equipment.erase(equipment.begin() + idx);
    }

    return p;
}

Cargo *SpaceStation::loadHumans(int idx)
{
    if (idx > humans.size() - 1)
        return nullptr;

    Cargo* h = humans.at(idx);
    humans.erase(humans.begin() + idx);
    return h;
}

SpaceStation *SpaceStation::clone()
{
    SpaceStation* temp = new SpaceStation();

    for (int i = 0; i < equipment.size(); i++)
    {
        pair<Cargo*,int> p;
        p.first = equipment.at(i).first;
        p.second = equipment.at(i).second;
        temp->equipment.push_back(p);
    }

    for (int i = 0; i < humans.size(); i++)
        temp->humans.push_back(humans.at(i));

    return temp;
}
