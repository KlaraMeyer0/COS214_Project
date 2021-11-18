#ifndef HUMANFACTORY_H
#define HUMANFACTORY_H

#include <string>
#include <iostream>
using namespace std;

#include "CargoFactory.h"

class HumanFactory : public CargoFactory
{
public:
	HumanFactory();
	~HumanFactory();
	Cargo *createCargo(string n);
};

#endif