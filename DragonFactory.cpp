#include "DragonFactory.h"
#include "DragonSpacecraft.h"

DragonFactory::DragonFactory() {}
DragonFactory::~DragonFactory() {}

Spacecraft *DragonFactory::createRocket()
{
    return new DragonSpacecraft();
}