#include "Cargo.h"

Cargo::Cargo(string n, bool h) : name(n){};

Cargo::~Cargo(){};

string Cargo::getName()
{
    return name;
}

bool Cargo::isHuman()
{
    return human;
}
