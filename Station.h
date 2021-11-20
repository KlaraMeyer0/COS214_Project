#ifndef STATION_H
#define STATION_H

#include "Cargo.h"
#include "StarlinkSatellite.h"
#include <map>

//Participant: ConcreteColleage in the Mediator Pattern

class StarlinkSatellite;

class Station
{
    public:
        Station();
        ~Station();
        void add(Station* stat);
        virtual void receiveCargo(Cargo* c);
        virtual void receiveCommunication(string com);
        virtual void printEquipment() = 0;
        virtual void printHumans() = 0;
        virtual pair<Cargo*, int>* loadEquipment(int idx) = 0;
        virtual Cargo* loadHumans(int idx) = 0;

        //used to update Space station of any changes to the StarlinkSatellites
        void updateStatus(StarlinkSatellite*);
        string name;
    private:
        Station* next;

        //Holds information on each StatlinkSatellite associated with it
        map<int ,bool> SatStatus;

};

#endif