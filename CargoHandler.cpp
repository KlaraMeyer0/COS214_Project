#include "CargoHandler.h"

CargoHandler::CargoHandler(): next(0) {}

void CargoHandler::add(CargoHandler* n)
{
    if (next)
        next->add(n);
    else
        next = n;
}

void CargoHandler::handleCargo(Cargo* c)
{
    if (c != nullptr)
    {
        if (next)
        {
            next->handleCargo(c);
        }
        else
        {
            cout << c->getName() << " cannot be delivered." << endl;
        }
    }
        cout << c->getName() << " has been delivered." << endl;
}

CargoHandler::~CargoHandler()
{


}
