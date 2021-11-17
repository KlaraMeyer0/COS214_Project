#include "EquipmentFactory.h"
#include "Equipment.h"

EquipmentFactory::EquipmentFactory() {}
EquipmentFactory::~EquipmentFactory() {}

Cargo *EquipmentFactory::createCargo(string n)
{
    return new Equipment(n);
}