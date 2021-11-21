#include "Equipment.h"

Equipment::Equipment(string name) : Cargo(name, false)
{

};

Equipment::~Equipment(){};

Cargo *Equipment::clone()
{
    return new Cargo(getName(), isHuman());
};