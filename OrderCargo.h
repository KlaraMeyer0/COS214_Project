#ifndef ORDERCARGO_H
#define ORDERCARGO_H

#include "Work.h"
#include "EquipmentFactory.h"
#include "HumanFactory.h"
#include "BaseStation.h"

class OrderCargo : public Work
{
public:
    OrderCargo(BaseStation* b);
    ~OrderCargo();
    void execute();
    void undo();
private:
    CargoFactory *equipment_factory;
    CargoFactory *human_factory;
    BaseStation* base_station;
};

#endif