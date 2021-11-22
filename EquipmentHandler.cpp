
#include <string>

using namespace std;

#include "EquipmentHandler.h"

EquipmentHandler::EquipmentHandler() : CargoHandler(), human(false) {}

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
                cout << "NAME MATCH" << endl;
                found = true;
                p.second = p.second + 1;
            }
            i++;
        }

        if (!found)
        {
            p.first = c;
            p.second = 1;
            s->equipment.push_back(p);
        }


    }
    CargoHandler::handleCargo(c,s);
}