#include "DragonRocketship.h"

DragonRocketship::DragonRocketship(string n) : Rocketship(n, 'd')
{

    cargo = nullptr;
    spacecraft = nullptr;
    rocket = nullptr;
}

DragonRocketship::~DragonRocketship()
{
    if (cargo != nullptr)
    {
        if (spacecraft != nullptr)
            for (int i = 0; i < spacecraft->getCapacity(); i++)
                cargo[i] = nullptr;
        delete[] cargo;
    }
}

void DragonRocketship::Launch(Station* ss)
{
    this->countdown();
    rocket->turnOn();
    this->attachToStation(ss);
    Station *station = ss;
    for (int i = 0; i < spacecraft->getCapacity(); i++)
    {
        if (cargo[i] != null)
        {
            station->receiveCargo(cargo[i]);
            cargo[i] = null;
        }
    }
}

Rocketship *DragonRocketship::clone()
{
    DragonRocketship *temp = new DragonRocketship(this->getName());
    temp->spacecraft = (this->spacecraft)->clone();
    temp->rocket = (this->rocket)->clone();

    return temp;
}

void DragonRocketship::attachSpacecraft(Spacecraft *s)
{
    spacecraft = s;
}

void DragonRocketship::attachRocket(FalconRocket *r)
{
    rocket = r;
}

void DragonRocketship::attachCargo(vector<Cargo *> cvect)
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

Cargo *DragonRocketship::dropCargo()
{
    cout << "Implement dropCargo" << endl;
}
int DragonRocketship::getRockets()
{
    return rocket->getEngine()->EngineCount();
}
bool DragonRocketship::testFire()
{
    rocket->turnOn();
    bool b = rocket->getState();
    rocket->turnOff();
    return b;
}
bool DragonRocketship::testLoading()
{
    return cargo == NULL ? false : true;
}