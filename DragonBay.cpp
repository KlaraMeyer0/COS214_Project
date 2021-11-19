#include "DragonBay.h"

DragonBay::DragonBay()
{
    dragon = new DragonRocketship();
}
DragonBay::~DragonBay() {}

DragonRocketship *DragonBay::getRocketship() {}

void DragonBay::buildRocket()
{
    RocketFactory *factorty = new FalconHeavyFactory();
    dragon->attachRocket(factorty->startFactory());
}

void DragonBay::buildBody()
{
    SpacecraftFactory *factorty = new DragonFactory();
    dragon->attachSpacecraft(factorty->startFactory());
}

void DragonBay::addCargo()
{
    // use Base station to load cargo ;)
    cout << "LOAD FROM BASE STATION" << endl;
}