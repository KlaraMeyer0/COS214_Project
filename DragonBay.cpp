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

void DragonBay::setName(string n, Station *s)
{
    dragon = new DragonRocketship(n);
    dragon->attachToStation(s);
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
    cout << "Load from " << dragon->getStation()->name << endl;
    dragon->getStation()->printEquipment();
}