#include "DragonBay.h"

DragonBay::DragonBay()
{
    dragon = nullptr;
    falconheavy_factory = new FalconHeavyFactory();
    dragon_factory = new DragonFactory();
}
DragonBay::~DragonBay()
{
    delete falconheavy_factory;
    delete dragon_factory;
}

DragonRocketship *DragonBay::getRocketship()
{
    return dragon;
}

void DragonBay::setName(string n)
{
    dragon = new DragonRocketship(n);
}

void DragonBay::buildRocket()
{
    dragon->attachRocket(falconheavy_factory->startFactory());
}

void DragonBay::buildBody()
{
    dragon->attachSpacecraft(dragon_factory->startFactory());
}

void DragonBay::addCargo()
{
    // use Base station to load cargo ;)
    cout << "LOAD FROM BASE STATION" << endl;
}