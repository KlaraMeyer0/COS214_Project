#include "ConcreteCargoHandler.h"

ConcreteCargoHandler(bool h) : human(h) {}

void ConcreteCargoHandler::handleCargo(Cargo* c)
{
    if (c->isHuman() && human)
        humans.push_back(c);

    if (!c->isHuman() && !human)
    {
        pair<Cargo *, int> p;
        p.first = c;
        p.second = amount;

        equipment.push_back(p);
    }
}