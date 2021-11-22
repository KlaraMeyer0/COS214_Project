/**
 * @file EquipmentHandler.h
 * @author Klara Meyer
 *
 * @brief
 *
 * Design Pattern: Chain of Responsibility
 * Participant: Concrete Handler
 */

#ifndef EQUIPMENTHANDLER_H
#define EQUIPMENTHANDLER_H

#include "CargoHandler.h"

class EquipmentHandler : public CargoHandler
{
    public:
        /**
         * Constructor that sets the human attribute to false.
         */
        EquipmentHandler();

        /**
         * Adds equipment to the specified station
         *
         * @param c The cargo (equipment) to be added
         * @param s The station where the cargo must be added
         */
        void handleCargo(Cargo* c, Station* s);
    public:
        /**
         * Indicates whether the concrete CargoHandler handles humans or equipment. In this case, equipment.
         */
        bool human;
};

#endif
