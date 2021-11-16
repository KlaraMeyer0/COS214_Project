#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

using namespace std;

#include "Satellite.h"
#include "ConcreteCommunicationRelay.h"
#include <string>

class StarlinkSatellite : public Satellite {
private:
    bool status;
    ConcreteCommunicationRelay* relay;
    string communicatesWith;
    StarlinkSatellite* next;
    StarlinkSatellite* previous;
public:
	StarlinkSatellite(string, ConcreteCommunicationRelay*);
	~StarlinkSatellite();
    void setStatus();
    string getCommunicatesWith();
    bool getStatus();
    StarlinkSatellite* clone();
};

#endif