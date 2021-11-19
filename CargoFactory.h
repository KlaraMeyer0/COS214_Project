#ifndef CARGOFACTORY_H
#define CARGOFACTORY_H

using namespace std;

#include "Cargo.h"

class CargoFactory
{
public:
    CargoFactory();
    ~CargoFactory();
    virtual Cargo *getCargo(string n) = 0;
    Cargo *startFactory();

private:
    Cargo *cargo;
};

#endif