
#ifndef CARGOHANDLER_H
#define CARGOHANDLER_H

#include "Cargo.h"
#include "Station.h"

class CargoHandler
{
    public:
        CargoHandler();
        ~CargoHandler();
        void add(CargoHandler* n);
        virtual void handleCargo(Cargo* c, Station* s);
    private:
        CargoHandler* next;
};

#endif
