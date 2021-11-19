#include "DragonSpacecraft.h"

DragonSpacecraft::DragonSpacecraft(int capacity) : Spacecraft(capacity) {}

DragonSpacecraft::~DragonSpacecraft() {}

Spacecraft *DragonSpacecraft::clone()
{
    return new DragonSpacecraft(getCapacity());
}