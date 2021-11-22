/**
 * @file EquipmentHandler.h
 * @author Klara Meyer
 *
 * @brief
 *
 * Design Pattern: Chain of Responsibility
 * Participant: Iterator
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
        void handleCargo(Cargo* c, Station* s);
    public:
        bool human;
};

#endif
