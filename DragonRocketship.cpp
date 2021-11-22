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
    this->dropCargo();
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

void DragonRocketship::dropCargo()
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

int DragonRocketship::getRockets()
{
    return rocket->getEngine()->EngineCount();
}

bool DragonRocketship::testFire()
{
    return rocket->getEngine()->testFire();
}

bool DragonRocketship::testLoading()
{
    return cargo == NULL ? false : true;
}

void DragonRocketship::startLanding()
{
    
}