#ifndef BASESTATION_H
#define BASESTATION_H

using namespace std;

#include "Station.h"

class BaseStation : public Station
{
    private:
        Cargo* cargo;
    public:
        BaseStaion(Cargo* c);
        ~BaseStaion();
        void receiveCargo(Cargo* c);
        void receiveCommunication(string s);
};

#endif
