#include "ConcreteCargoHandler.h"

ConcreteCargoHandler(bool h) : human(h) {}

void ConcreteCargoHandler::handleCargo(Cargo* c)
{
    if (c->isHuman() && human)
        humans.push_back(c);

    if (!c->isHuman() && !human)
    {
        bool found = false;

        pair<Cargo *, int> p;
        int i = 0;
        while ( i < equipment.size() && !found)
        {
            p = equipment.at(i);
            if (strcmp(p.first,c->getName()) == 0)
            {
                found = true;
                p.second = p.second + 1;
            }
            i++;
        }

        if (!found)
        {
            p.first = c;
            p.second = 0;
            equipment.push_back(p);
        }
    }
}