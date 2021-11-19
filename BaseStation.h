#ifndef BASESTATION_H
#define BASESTATION_H

#include <vector>

using namespace std;

#include "Station.h"

class BaseStation : public Station
{
    public:
        BaseStation();
        ~BaseStation();
        void receiveCargo(Cargo* c);
        void receiveCommunication(string s);
    private:
        vector<Cargo*> equipment;
        vector<Cargo*> humans;

        //humans arriving at base station: call factory for humans
        //cargo delivered to base station: call factory for cargo

        //add cargo to rockets from here
};

#endif
