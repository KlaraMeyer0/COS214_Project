#ifndef BASESTATION_H
#define BASESTATION_H
#include "Station.h"
using namespace std;


class BaseStation : public Station
{
    public:
        BaseStation();
        ~BaseStation();
        void receiveCargo(Cargo* c);
        void receiveCommunication(string s);
    private:
        Cargo* equipment;
        Cargo* humans;

        //humans arriving at base station: call factory for humans
        //cargo delivered to base station: call factory for cargo

        //add cargo to rockets from here
};

#endif
