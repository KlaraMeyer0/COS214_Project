
#include <string>

using namespace std;

#include "HumanHandler.h"

HumanHandler::HumanHandler() : CargoHandler(), human(true) {}

void HumanHandler::handleCargo(Cargo* c, Station* s)
{
  cout << "CURRENTLY IN HumanHandler's handleCargo" << endl;

    if (c->isHuman() == human)
        s->humans.push_back(c);

    CargoHandler::handleCargo(c,s);
}