/**
 * @file HumanHandler.h
 * @class HumanHandler
 * @author Klara Meyer
 * @brief Inherits from CargoHandler, Design Pattern: Chain of Responsibility, Participant: Concrete Handler
 */

#ifndef HUMANHANDLER_H
#define HUMANHANDLER_H

#include "CargoHandler.h"

class HumanHandler : public CargoHandler
{
    public:
        /**
         * Constructor that sets the human attribute to true.
         */
        HumanHandler();

        /**
         * Adds humans to the specified station
         *
         * @param c The cargo (human) to be added
         * @param s The station where the cargo must be added
         */
        void handleCargo(Cargo* c, Station* s);
    public:
        /**
         * Indicates whether the concrete CargoHandler handles humans or equipment. In this case, humans.
         */
        bool human;
};

#endif
