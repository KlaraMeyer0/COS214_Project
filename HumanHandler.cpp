
#include <string>

using namespace std;

#include "HumanHandler.h"

HumanHandler::HumanHandler(bool h) : human(h) {}

void HumanHandler::handleCargo(Cargo* c, Station* s)
{
    if (c->isHuman() == human)
        s->humans.push_back(c);

    CargoHandler::handleCargo(c,s);
}