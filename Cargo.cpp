#include "Cargo.h"

Cargo::Cargo(string n) : name(n) {};

Cargo::~Cargo() {};

string Cargo::getName()
{
    return name;
}