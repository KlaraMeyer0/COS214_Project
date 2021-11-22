/**
 * @file HumanHandler.h
 * @author Klara Meyer
 *
 * @brief
 *
 * Design Pattern: Chain of Responsibility
 * Participant: Concrete Handler
 */

#ifndef HUMANHANDLER_H
#define HUMANHANDLER_H

#include "CargoHandler.h"

class HumanHandler : public CargoHandler
{
    public:
        /**
         * Constructor that sets the human attribute to true if it handles humans and false if it doesn't handle humans.
         *
         * @param h
         */
        HumanHandler(bool h);
        void handleCargo(Cargo* c, Station* s);
    public:
        bool human;
};

#endif
