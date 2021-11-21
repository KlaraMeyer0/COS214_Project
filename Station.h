#ifndef STATION_H
#define STATION_H

#include "Cargo.h"
#include "StarlinkSatellite.h"
#include <map>

//Participant: ConcreteColleage in the Mediator Pattern

class StarlinkSatellite;
class CommunicationRelay;

class Station
{
    public:
        Station();
        virtual ~Station();
        void add(Station* stat);
        virtual void receiveCargo(Cargo* c);
        virtual void receiveCommunication(string com);
        virtual void printEquipment() = 0;
        virtual void printHumans() = 0;
        virtual pair<Cargo*, int>* loadEquipment(int idx, int num) = 0;
        virtual Cargo* loadHumans(int idx) = 0;

        //used to update Space station of any changes to the StarlinkSatellites
        void updateStatus(StarlinkSatellite*);

        //wrapper on the sation to resolve an error on one of the starlinksattelites
        void resolve(StarlinkSatellite* obj);

        void attachRelay(CommunicationRelay*);

        string name;
    private:
        Station* next;

        //Holds information on each StatlinkSatellite associated with it
        map<int ,bool> SatStatus;

        //Mediator this colleague communicates with 
        CommunicationRelay* relayTo;

};

#endif