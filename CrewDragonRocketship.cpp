#include "CrewDragonRocketship.h"

CrewDragonRocketship::CrewDragonRocketship(string n) : Rocketship(n, 'c')
{
    cargo = nullptr;
    spacecraft = nullptr;
    rocket = nullptr;
}

CrewDragonRocketship::~CrewDragonRocketship()
{
    if (cargo != nullptr)
    {
        if (spacecraft != nullptr)
            for (int i = 0; i < spacecraft->getCapacity(); i++)
                cargo[i] = nullptr;
        delete[] cargo;
    }
}

void CrewDragonRocketship::Launch(Station *ss)
{
    this->countdown();
    rocket->turnOn();
    this->attachToStation(ss);
}

Rocketship *CrewDragonRocketship::clone()
{
    CrewDragonRocketship *temp = new CrewDragonRocketship(this->getName());
    temp->spacecraft = (this->spacecraft)->clone();
    temp->rocket = (this->rocket)->clone();

    return temp;
}

void CrewDragonRocketship::attachSpacecraft(Spacecraft *s)
{
    spacecraft = s;
}

void CrewDragonRocketship::attachRocket(FalconRocket *r)
{
    rocket = r;
}

void CrewDragonRocketship::attachCargo(vector<Cargo *> cvect)
{
    cargo = new Cargo *[spacecraft->getCapacity()];
    int toFill = cvect.size();
    if (toFill > spacecraft->getCapacity())
    {
        cout << "There is not enough space on the " << this->getName() << " for all the cargo" << endl;
        toFill = spacecraft->getCapacity(); // only fill the available space
    }
    for (int i = 0; i < toFill; i++)
        cargo[i] = cvect[i];
}

void CrewDragonRocketship::dropCargo()
{
    Station *station = this->getStation();
    if (cargo[0] == NULL)
        cout << "There is no Cargo to unlaod" << endl;
    for (int i = 0; i < spacecraft->getCapacity(); i++)
    {
        if (cargo[i] != NULL)
        {
            station->receiveCargo(cargo[i]);
            cargo[i] = NULL;
        }
    }
}

int CrewDragonRocketship::getRockets()
{
    return rocket->getEngine()->EngineCount();
}
bool CrewDragonRocketship::testFire()
{
    rocket->turnOn();
    bool b = rocket->getState();
    rocket->turnOff();
    return b;
}
bool CrewDragonRocketship::testLoading()
{
    return cargo == NULL ? false : true;
}