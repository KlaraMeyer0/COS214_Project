#include "CrewDragonRocketship.h"

CrewDragonRocketship::CrewDragonRocketship(string n) : Rocketship(n)
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

void CrewDragonRocketship::Launch() {}

Rocketship *CrewDragonRocketship::clone()
{
    CrewDragonRocketship *temp = new CrewDragonRocketship(this->getName());
    temp->spacecraft = (this->spacecraft)->clone();
    temp->rocket = (this->rocket)->clone();
}

void CrewDragonRocketship::attachSpacecraft(Spacecraft *s)
{
    spacecraft = s;
}

void CrewDragonRocketship::attachRocket(FalconRocket *r)
{
    rocket = r;
}

void CrewDragonRocketship::attachCargo(Cargo **c, int size)
{
    cargo = new Cargo *[spacecraft->getCapacity()];
    int toFill = size;
    if (size > spacecraft->getCapacity())
    {
        cout << "There is not enough space on the " << this->getName() << " for all the cargo" << endl;
        toFill = spacecraft->getCapacity(); // only fill the available space
    }
    for (int i = 0; i < toFill; i++)
        cargo[i] = c[i];
}

Cargo *CrewDragonRocketship::dropCargo()
{
    cout << "Implement dropCargo" << endl;
}