#include "Spacecraft.h"

Spacecraft::Spacecraft(int capacity)
{
    cargoCapacity = capacity;
}

Spacecraft::~Spacecraft() {}

int Spacecraft::getCapacity()
{
    return cargoCapacity;
}