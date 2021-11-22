#include <iostream>

using namespace std;

#include "CargoHandler.h"

using namespace std;

#include <iostream>

CargoHandler::CargoHandler(): next(0) {}

void CargoHandler::add(CargoHandler* n)
{
    if (next)
        next->add(n);
    else
        next = n;
}

void CargoHandler::handleCargo(Cargo* c, Station* s)
{
    if (c != nullptr)
    {
        cout << "THE CARGO RECEIVED IS NOT NULL: YAY" << endl;
        if (next)
        {
            next->handleCargo(c, s);
        }
        else
        {
            cout << c->getName() << " cannot arrive at " << s->getName() << endl;
        }
    }
    else
        cout << c->getName() << " has arrived at " << s->getName() << endl;
}

CargoHandler::~CargoHandler()
{


}
