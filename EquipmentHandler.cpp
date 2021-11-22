
#include <string>

using namespace std;

#include "EquipmentHandler.h"

EquipmentHandler::EquipmentHandler(bool h) : human(h) {}

void EquipmentHandler::handleCargo(Cargo* c, Station* s)
{
    if (c->isHuman() == human)
    {
        bool found = false;

        pair<Cargo *, int> p;
        int i = 0;
        while ( i < s->equipment.size() && !found)
        {
            p = s->equipment.at(i);
            if (p.first->getName() == c->getName())
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
            s->equipment.push_back(p);
        }
    }
}