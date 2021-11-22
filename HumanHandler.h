/**
 * @file ConcreteCargoHandler.h
 * @author Klara Meyer
 *
 * @brief
 *
 * Design Pattern: Chain of Responsibility
 * Participant: Iterator
 */

#ifndef HUMANHANDLER_H
#define HUMANHANDLER_H

#include "CargoHandler.h"

class ConcreteCargoHandler : public CargoHandler
{
    public:
        /**
         * Constructor that sets the human attribute to true if it handles humans and false if it doesn't handle humans.
         *
         * @param h
         */
        ConcreteCargoHandler(bool h);
        void handleCargo(Cargo* c, Station* s);
    public:
        bool human;
};

#endif
