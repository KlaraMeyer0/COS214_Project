/**
 * @file CargoHandler.h
 * @author Klara Meyer
 *
 * @brief
 *
 * Design Pattern: Chain of Responsibility
 * Participant: Handler
 */

#ifndef CARGOHANDLER_H
#define CARGOHANDLER_H

#include "Cargo.h"
#include "Station.h"

class CargoHandler
{
    public:
        /**
         * Constructor for CargoHandler
         */
        CargoHandler();

        /**
         * Destructor for CargoHandler
         */
        ~CargoHandler();

        /**
         * Adds a concrete CargoHandler
         *
         * @param n Concrete CargoHandler
         */
        void add(CargoHandler* n);

        /**
         * Calls the handleCargo implementations of the concrete CargoHandler classes in order for the
         * cargo to be handled in the correct way
         *
         * @param c Cargo to be handled
         * @param s Station to which cargo is sent
         */
        virtual void handleCargo(Cargo* c, Station* s);
    private:
        /**
         * Stores the next concrete CargoHandler
         */
        CargoHandler* next;
};

#endif
