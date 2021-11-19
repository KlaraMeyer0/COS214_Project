#ifndef STATION_H
#define STATION_H
#include "PointOfCommunication.h"
#include "Cargo.h"
#include <string>
using namespace std;


class Station : public PointOfCommunication{
    private:
        Station* next;
    public:
        Station();
        ~Station();
        void add(Station* stat);
        virtual void receiveCargo(Cargo* c);
        virtual void receiveCommunication(string com);
    };

#endif