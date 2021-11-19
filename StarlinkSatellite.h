#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

using namespace std;

#include "Satellite.h"
#include "Station.h"
#include "CommunicationRelay.h"
#include <string>

class StarlinkSatellite : public Satellite, public Station {
public:
	StarlinkSatellite(string, CommunicationRelay*);//talk to me (Xander) when you are done/starting with this such that I can update the Factory Method
	~StarlinkSatellite();
    void setStatus();
    string getCommunicatesWith();
    bool getStatus();
    StarlinkSatellite* clone();
    void setName(int);
    StarlinkSatellite* next;
    StarlinkSatellite* previous;
private:
    bool status;
    CommunicationRelay* relay;
    string communicatesWith;
    int name;
};

#endif