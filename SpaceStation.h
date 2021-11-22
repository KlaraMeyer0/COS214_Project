/**
 * @file SpaceStation.h
 * @class SpaceStation
 * @author Klara Meyer
 *
 * @brief Not part of a specific pattern
 */

#ifndef SPACESTATION_H
#define SPACESTATION_H

#include <vector>

using namespace std;

#include "Station.h"
#include "HumanHandler.h"
#include "EquipmentHandler.h"

class SpaceStation : public Station
{
    public:
        /**
         * @brief Constructor that initialises the name of the station
         */
        SpaceStation();

        /**
         * @brief Destructor for SpaceStation
         */
        virtual ~SpaceStation();

        /**
         * @brief Function for receiving cargo at the space station
         *
         * @param c Cargo to be received
         */
        void receiveCargo(Cargo *c);

        /**
         * @brief Function for receiving communication at the space station
         *
         * @param s Communication to be received
         */
        void receiveCommunication(string s);

        /**
         * @brief Prints the names and the amounts of each type of equipment at the space station
         */
        void printEquipment();

        /**
         * @brief Prints the names of the humans at the space station
         */
        void printHumans();

        /**
         * @brief Used for loading equipment from the space station into a rocket
         *
         * @param idx Specifies which equipment should be loaded
         * @param num Specifies how many pieces of equipment should be loaded
         * @return A pair containing the item and the number of items to be loaded
         */
        pair<Cargo*, int> loadEquipment(int idx, int num);

        /**
         * @brief Used for having humans board a rocket from the space station
         *
         * @param idx Specifies which humans should board the rocket
         * @return The item of cargo (human) to be loaded onto the rocket
         */
        Cargo* loadHumans(int idx);

        /**
         * @brief used for cloning the space station
         * @return
         */
        SpaceStation* clone();

    private:
        /**
         * @brief Stores a pointer to the handler that handles the cargo arriving at the space station
         */
        CargoHandler* handler;
};

#endif
