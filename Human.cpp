#include "Human.h"

Human::Human(string name) : Cargo(name, true) {};

Human::~Human() {}

Cargo *Human::clone()
{
    return new Cargo(getName(), isHuman());
};