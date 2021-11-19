#ifndef SPACESTATION_H
#define SPACESTATION_H

using namespace std;

#include "Station.h"

class SpaceStaion : public Station
{
    private:
        Cargo* cargo;
    public:
        SpaceStaion(Cargo* c);
        ~SpaceStaion();
        void receiveCargo(Cargo* c);
        void receiveCommunication(string s);
};

#endif
