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
        void receiveCargo(Cargo *c, int amount);
        void receiveCommunication(string s);
        void printEquipment();
        void printHumans();
        pair<Cargo*, int>* loadCargo(int idx);
        Cargo* loadHumans(int idx);

        //Luca->Klara :Please implement me 
        SpaceStation* clone();
        
    private:
        vector<pair<Cargo *, int>> equipment;
        vector<Cargo *> humans;
};

#endif
