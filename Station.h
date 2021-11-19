#ifndef STATION_H
#define STATION_H

using namespace std;

#include "Cargo.h"
#include "StarlinkSatellite.h"
#include <map>

class Station
{
    public:
        Station();
        ~Station();
        void add(Station* stat);
        virtual void receiveCargo(Cargo* c);
        virtual void receiveCommunication(string com);
        void updateStatus(StarlinkSatellite*);
    private:
        Station* next;
        map<int ,bool> SatStatus;
};

#endif