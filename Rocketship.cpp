#include "Rocketship.h"

Rocketship::Rocketship(string n)
{
    name = n;
}

Rocketship::~Rocketship() {}

string Rocketship::getName()
{
    return name;
}