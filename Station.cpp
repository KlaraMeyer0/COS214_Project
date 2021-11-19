

using namespace std;

#include "Station.h"


Station::Station() : next(0) {}

Station::~Station() {}

void Station::add(Station *stat)
{
    if (next)
        next->add(stat);
    else
        next = stat;
}

void Station::receiveCargo(Cargo *c)
{
    if (c != nullptr)
        if (next)
            next->receiveCargo(c);
        else
            cout <<
}

void Station::receiveCommunication(string com)
{

}
