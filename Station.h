#ifndef STATION_H
#define STATION_H

using namespace std;

#include "Cargo.h"

class Station {
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
