#ifndef STATION_H
#define STATION_H

using namespace std;

#include "Cargo.h"
#include "StarlinkSatellite.h"
#include <map>

//Participant: ConcreteColleage in the Mediator Pattern

class Station
{
    public:
        Station();
        ~Station();
        void add(Station* stat);
        virtual void receiveCargo(Cargo* c);
        virtual void receiveCommunication(string com);

        //used to update Space station of any changes to the StarlinkSattelites
        void updateStatus(StarlinkSatellite*);
    private:
        Station* next;

        //Holds information on each StatlinkSattellite associated with it
        map<int ,bool> SatStatus;
};

#endif