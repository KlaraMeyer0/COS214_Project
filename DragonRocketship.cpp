#include "DragonRocketship.h"

DragonRocketship::DragonRocketship(string n) : Rocketship(n,'d')
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

void DragonRocketship::Launch() {}

Rocketship *DragonRocketship::clone()
{
    DragonRocketship *temp = new DragonRocketship(this->getName());
    temp->spacecraft = (this->spacecraft)->clone();
    temp->rocket = (this->rocket)->clone();
}

void DragonRocketship::attachSpacecraft(Spacecraft *s)
{
    spacecraft = s;
}

void DragonRocketship::attachRocket(FalconRocket *r)
{
    rocket = r;
}

void DragonRocketship::attachCargo(Cargo **c, int size)
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

Cargo *DragonRocketship::dropCargo()
{
    cout << "Implement dropCargo" << endl;
}
FalconRocket* CrewDragonRocketship::getRocket(){
    
}