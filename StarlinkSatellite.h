#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

using namespace std;

#include "Satellite.h"
#include "CommunicationRelay.h"
#include <string>

class StarlinkSatellite : public Satellite {
private:
    bool status;
    CommunicationRelay* relay;
    string communicatesWith;
    StarlinkSatellite* next;
    StarlinkSatellite* previous;
public:
	StarlinkSatellite(string, CommunicationRelay*);
	~StarlinkSatellite();
    void setStatus();
    string getCommunicatesWith();
    bool getStatus();
    StarlinkSatellite* clone();
};

#endif