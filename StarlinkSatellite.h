#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

using namespace std;

#include "Satellite.h"
#include "Station.h"
#include "CommunicationRelay.h"
#include <string>

class StarlinkSatellite : public Satellite, public Station {
private:
    bool status;
    CommunicationRelay* relay;
    string communicatesWith;
    StarlinkSatellite* next;
    StarlinkSatellite* previous;
    int name;
public:
	StarlinkSatellite(string, CommunicationRelay*);
	~StarlinkSatellite();
    void setStatus();
    string getCommunicatesWith();
    bool getStatus();
    StarlinkSatellite* clone();
    void setName(int);
};

#endif