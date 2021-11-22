#include <iostream>

using namespace std;

#include "BaseStation.h"

BaseStation::BaseStation() : Station()
{
    setName("KJLXR-28564");
    handler = new CargoHandler();
    handler->add(new EquipmentHandler(true));
    handler->add(new EquipmentHandler(false));
}

BaseStation::~BaseStation()
{
    delete handler;
}

void BaseStation::receiveCargo(Cargo *c)
{

    handler->handleCargo(c, this);

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

pair<Cargo *, int> *BaseStation::loadEquipment(int idx, int num)
{
    if (idx > equipment.size() - 1)
        return nullptr;

    pair<Cargo *, int> *p;
    p->first = equipment.at(idx).first;
    p->second = num;

    if (equipment.at(idx).second > num)
    {
        equipment.at(idx).second -= num;
    }
    else if (equipment.at(idx).second <= num)
    {
        p->second = equipment.at(idx).second;
        equipment.erase(equipment.begin() + idx);
    }

    return p;
}

Cargo *BaseStation::loadHumans(int idx)
{
    if (idx > humans.size() - 1)
        return nullptr;

    Cargo *h = humans.at(idx);
    humans.erase(humans.begin() + idx);
    return h;
}

BaseStation *BaseStation::clone()
{
    BaseStation *temp = new BaseStation();

    for (int i = 0; i < equipment.size(); i++)
    {
        pair<Cargo *, int> p;
        p.first = equipment.at(i).first;
        p.second = equipment.at(i).second;
        temp->equipment.push_back(p);
    }

    for (int i = 0; i < humans.size(); i++)
        temp->humans.push_back(humans.at(i));

    return temp;
}
