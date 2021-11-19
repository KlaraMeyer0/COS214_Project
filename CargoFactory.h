#ifndef CARGOFACTORY_H
#define CARGOFACTORY_H

#include "Cargo.h"

class CargoFactory
{
public:
    CargoFactory();
    ~CargoFactory();
    Cargo *startFactory(string n);
protected:
    virtual Cargo *getCargo(string n) = 0;
};

#endif