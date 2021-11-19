#include "EquipmentFactory.h"
#include "Equipment.h"

EquipmentFactory::EquipmentFactory() {}
EquipmentFactory::~EquipmentFactory() {}

Cargo *EquipmentFactory::getCargo(string n)
{
    return new Equipment(n);
}