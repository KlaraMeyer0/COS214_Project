#ifndef CONCRETECARGOHANDLER_H
#define CONCRETECARGOHANDLER_H

#include "CargoHandler.h"

class ConcreteCargoHandler : public CargoHandler
{
    public:
        ConcreteCargoHandler(bool h);
        void handleCargo(Cargo* c, Station* s);
    public:
        bool human;
};

#endif
