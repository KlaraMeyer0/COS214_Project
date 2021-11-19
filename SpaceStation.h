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
    private:
        vector<Cargo*> equipment;
        vector<Cargo*> humans;
};

#endif
