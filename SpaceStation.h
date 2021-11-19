#ifndef SPACESTATION_H
#define SPACESTATION_H

using namespace std;

#include "Station.h"

class SpaceStaion : public Station
{
    public:
        SpaceStaion(Cargo* c);
        ~SpaceStaion();
        void receiveCargo(Cargo* c);
        void receiveCommunication(string s);
    private:
        Cargo* cargo;
        Cargo* humans;
};

#endif
