#include "HumanFactory.h"
#include "Human.h"

HumanFactory::HumanFactory() {}
HumanFactory::~HumanFactory() {}

Cargo *HumanFactory::getCargo(string n)
{
    // cout << "Enter name of astronaut: ";
    // string name;
    // cin >> name;
    return new Human(n);
}