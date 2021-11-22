/**
 * @file Station.h
 * @class Station
 * @author {Klara Meyer ,Luca Loubser}
 * 
 * @brief
 * Design Pattern: Mediator
 * Participant: ConcreteColleage
 */

#ifndef STATION_H
#define STATION_H

#include "Cargo.h"
#include "StarlinkSatellite.h"
#include <map>

class StarlinkSatellite;
class CommunicationRelay;

class Station{
    public:
        /**
         * @brief Creates a new station
         */
        Station();

        /**
         * @brief Destructor of the Station
         */
        virtual ~Station();

        /**
         * @brief Pure virtual function for receiving cargo at a station
         *
         * @param c Cargo to be received
         */
        virtual void receiveCargo(Cargo *c) = 0;

        /**
         * @brief Pure virtual function for receiving communication at a station
         *
         * @param com Communication to be received
         */
        virtual void receiveCommunication(string com) = 0;

        /**
         * @brief Pure virtual function for printing equipment stored at a station
         */
        virtual void printEquipment() = 0;

        /**
         * @brief Pure virtual function for printing humans present at a station
         */
        virtual void printHumans() = 0;

        /**
         * @brief Pure virtual function for loading equipment from a station into a rocket
         *
         * @param idx Specifies which equipment should be loaded
         * @param num Specifies how many pieces of equipment should be loaded
         * @return A pair containing the item and the number of items to be loaded
         */
        virtual pair<Cargo *, int> loadEquipment(int idx, int num) = 0;

        /**
         * @brief Pure virtual function for having humans board a rocket from a station
         *
         * @param idx Specifies which humans should board the rocket
         * @return The item of cargo (human) to be loaded onto the rocket
         */
        virtual Cargo *loadHumans(int idx) = 0;

        /**
         * @brief used to update a Station of any changes to a StarlinkSatellites ,
         *        through the CommunicationRelay
         * @param StarlinkSatellite that updates the Station
        */
        //used to update Space station of any changes to the StarlinkSatellites
        void updateStatus(StarlinkSatellite *);

        /**
         * @brief resolve an error on one of the StarlinkSatellite, by setting its status to true
         *        indicating it is functional ,through the CommunicationRelay member
         * @param StarlinkSatellite to communicate with
         */
        void resolve(StarlinkSatellite* obj);

        /**
         * @brief sets the CommunicationRelay* member: relayTo
         * @param CommunicationRelay pointer
         */ 
        void attachRelay(CommunicationRelay*);

        /**
         * @brief returns the name of the Station
         * @return string
         */ 
        string getName();

        /**
         * @brief sets the name of the Station
         * @param string
        */ 
        void setName(string n);

        /**
         * @brief returns the status of the StarlinkSatellites assocciated with this station
         * @return map<int ,bool> 
         */
        map<int, bool> getSatStatus();

        /**
         * @brief Vector of pairs storing each item at a station along with the number of an item
         */
        vector<pair<Cargo *, int>> equipment;

        /**
         * @brief Vector of cargo pointers storing pointers to humans at a station
         */
        vector<Cargo *> humans;

    private:
        //Station* next;

        ///@brief name of the station
        string name;

        ///@brief Holds information on each StarlinkSatellite associated with it
        map<int, bool> SatStatus;

        ///@brief CommunicationRelay this station communicates with
        CommunicationRelay *relayTo;

        void setSatStatus(map<int, bool> stat);

        void setRelay(CommunicationRelay *obj);

        CommunicationRelay *getRelay();
};

#endif