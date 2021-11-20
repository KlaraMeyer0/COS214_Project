#ifndef SPACESTATION_H
#define SPACESTATION_H

#include <vector>

using namespace std;

#include "Station.h"

class SpaceStation : public Station
{
    public:
        SpaceStation();
        ~SpaceStation();
        void receiveCargo(Cargo* c);
        void receiveCommunication(string s);
        void printEquipment();
        void printHumans();
        pair<Cargo*, int>* loadCargo(int idx);
        Cargo* loadHumans(int idx);
    private:
        vector<Cargo*> equipment;
        vector<Cargo*> humans;
};

#endif
