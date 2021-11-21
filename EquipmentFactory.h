#ifndef EQUIPMENTFACTORY_H
#define EQUIPMENTFACTORY_H

using namespace std;

#include "CargoFactory.h"

class EquipmentFactory : public CargoFactory {
public:
	EquipmentFactory();
	virtual ~EquipmentFactory();
protected:
    Cargo* getCargo(string n);
};

#endif