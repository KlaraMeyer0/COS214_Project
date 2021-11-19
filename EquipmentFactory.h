#ifndef EQUIPMENTFACTORY_H
#define EQUIPMENTFACTORY_H

using namespace std;

#include "CargoFactory.h"

class EquipmentFactory : public CargoFactory {
public:
	EquipmentFactory();
	~EquipmentFactory();
    Cargo* getCargo(string n);
};

#endif