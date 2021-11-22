/**
 * @file Station.h
 * @class Station
 * @author Klara Meyer ,Luca Loubser
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

        //void add(Station* stat);
        //virtual void receiveCargo(Cargo* c);
        virtual void receiveCommunication(string com) = 0;
        virtual void printEquipment() = 0;
        virtual void printHumans() = 0;
        virtual pair<Cargo*, int>* loadEquipment(int idx, int num) = 0;
        virtual Cargo* loadHumans(int idx) = 0;

        /**
         * @brief used to update a Station of any changes to a StarlinkSatellites ,
         *        through the CommunicationRelay
         * @param StarlinkSatellite that updates the Station
        */
        //used to update Space station of any changes to the StarlinkSatellites
        void updateStatus(StarlinkSatellite*);

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

        void setName(string n);

        /**
         * @brief returns the status of the StarlinkSatellites assocciated with this station
         * @return map<int ,bool> 
         */ 
        map<int ,bool> getSatStatus();

        vector<pair<Cargo *, int>> equipment;
        vector<Cargo *> humans;

        
    private:
        //Station* next;

        ///@brief name of the station
        string name;
        
        ///@brief Holds information on each StarlinkSatellite associated with it
        map<int ,bool> SatStatus;

        ///@brief CommunicationRelay this station communicates with
        CommunicationRelay* relayTo;

};

#endif