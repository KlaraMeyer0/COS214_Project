#ifndef EQUIPMENTFACTORY_H
#define EQUIPMENTFACTORY_H

using namespace std;

#include "CargoFactory.h"

class EquipmentFactory : public CargoFactory {
public:
	EquipmentFactory();
	~EquipmentFactory();
protected:
    Cargo* getCargo(string n);
};

#endif