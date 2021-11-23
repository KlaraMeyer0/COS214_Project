#include "DragonFactory.h"
#include "DragonSpacecraft.h"
#include <iostream>

DragonFactory::DragonFactory() {}
DragonFactory::~DragonFactory() {}

Spacecraft *DragonFactory::createRocket()
{
    cout << "Dragon spacecraft successfully created" << endl;
    return new DragonSpacecraft(50);
}