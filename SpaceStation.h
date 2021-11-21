#ifndef SPACESTATION_H
#define SPACESTATION_H

#include <vector>

using namespace std;

#include "Station.h"
#include "ConcreteCargoHandler.h"

class SpaceStation : public Station
{
    public:
        SpaceStation();
        virtual ~SpaceStation();
        void receiveCargo(Cargo *c);
        void receiveCommunication(string s);
        void printEquipment();
        void printHumans();
        pair<Cargo*, int>* loadEquipment(int idx, int num);
        Cargo* loadHumans(int idx);

        SpaceStation* clone();

    private:
        CargoHandler* handler;
};

#endif
