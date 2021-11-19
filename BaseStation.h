#ifndef BASESTATION_H
#define BASESTATION_H
#include "Station.h"
using namespace std;


class BaseStation : public Station
{
    private:
        Cargo* cargo;
    public:
        BaseStation(Cargo* c);
        ~BaseStation();
        void receiveCargo(Cargo* c);
        void receiveCommunication(string s);
};

#endif
