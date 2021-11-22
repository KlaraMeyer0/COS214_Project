#include <iostream>

using namespace std;

#include "BaseStation.h"

BaseStation::BaseStation() : Station()
{
    setName("Base-KJLXR-28564");
    //handler = new CargoHandler();
    //handler->add(new EquipmentHandler(true));
    handler = new HumanHandler();
    handler->add(new EquipmentHandler());
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
        cout << "Index: " << (i+1) << " Type: " << equipment.at(i).first->getName() << " Number: " << equipment.at(i).second << endl;
}

void BaseStation::printHumans()
{
    for (int i = 0; i < humans.size(); i++)
        cout << "index: " << (i+1) << " Name: " << humans.at(i)->getName() << endl;
}

pair<Cargo *, int> BaseStation::loadEquipment(int idx, int num)
{
cout << "BLAH" << endl;
    pair<Cargo *, int> p;
    p = make_pair(equipment.at(idx).first,p.second = num);

    if (idx > equipment.size() - 1)
    {
        p.second = -1;
        return p;
    }

cout << "Hi" << endl;
    if (equipment.at(idx).second > num)
    {
        equipment.at(idx).second -= num;
    }
    else if (equipment.at(idx).second <= num)
    {
        cout << "HERE PERHAPS???" << endl;
        p.second = equipment.at(idx).second;
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
