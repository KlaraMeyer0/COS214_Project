/**
 * @file OrderCargo.h
 * @class OrderCargo
 * @author Xander Coetzer
 * @brief Inherits from Work, Design Pattern: Command, Participant: Concrete Command
 */
#ifndef ORDERCARGO_H
#define ORDERCARGO_H

#include "Work.h"
#include "EquipmentFactory.h"
#include "HumanFactory.h"
#include "BaseStation.h"

class OrderCargo : public Work{
public:
    /**
     * @brief Construct a new Order Cargo object
     * 
     * @param b Base station pointer
     * @param l LaunchInterface pointer
     */
    OrderCargo(BaseStation* b,LaunchInterface* l);
    /**
     * @brief Destroy the Order Cargo object
     * 
     */
    virtual ~OrderCargo();
    /**
     * @brief Prompts the user with inputs to what Cargo to create and store in the base station
     * 
     */
    void execute();
    /**
     * @brief Not implemented for this class
     * 
     */
    void undo();
private:
    /**
     * @brief Factory used to create desired equipment
     * 
     */
    CargoFactory *equipment_factory;
    /**
     * @brief Factory used to create desired humans
     * 
     */
    CargoFactory *human_factory;
    /**
     * @brief Pointer to the base station where the cargo gets stored
     * 
     */
    BaseStation *base_station;
};

#endif