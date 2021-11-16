#ifndef CARGOFACTORY_H
#define CARGOFACTORY_H

using namespace std;

#include "Cargo.h"

class CargoFactory {
private:
    Cargo* cargo;
public:
	CargoFactory();
	~CargoFactory();
    virtual Cargo* createRocket() = 0;
    Cargo* startFactory();
};

#endif