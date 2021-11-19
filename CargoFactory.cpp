#include "CargoFactory.h"

CargoFactory::CargoFactory() {}
CargoFactory::~CargoFactory() {}

Cargo *CargoFactory::startFactory(string n)
{
    return getCargo(n);
}