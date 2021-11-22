#include "DragonFactory.h"
#include "DragonSpacecraft.h"
#include <iostream>

DragonFactory::DragonFactory() {}
DragonFactory::~DragonFactory() {}

Spacecraft *DragonFactory::createRocket()
{
    cout << "Dragon spacecraft successfully create" << endl;
    return new DragonSpacecraft(50);
}