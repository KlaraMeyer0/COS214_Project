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
         * Constructor that sets the human attribute to true if it handles humans and false if it doesn't handle humans.
         *
         * @param h
         */
        EquipmentHandler(bool h);

        /**
         * Adds equipment to the specified station
         *
         * @param c
         * @param s
         */
        void handleCargo(Cargo* c, Station* s);
    public:
        bool human;
};

#endif
