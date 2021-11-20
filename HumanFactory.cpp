#include "HumanFactory.h"
#include "Human.h"

HumanFactory::HumanFactory() {}
HumanFactory::~HumanFactory() {}

Cargo *HumanFactory::getCargo(string n)
{
    return new Human(n);
}