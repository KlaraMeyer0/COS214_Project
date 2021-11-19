

using namespace std;

#include "BaseStation.h"


BaseStation::BaseStation() : Station() {}

BaseStation::~BaseStation()
{

}

void BaseStation::receiveCargo(Cargo *c)
{
    Station::receiveCargo(c);
}

void BaseStation::receiveCommunication(string s)
{
    Station::receiveCommunication(s);
}
