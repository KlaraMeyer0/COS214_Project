#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H
#include "PointOfCommunication.h"
#include "CommunicationRelay.h"
#include <string>
using namespace std;


class StarlinkSatellite : public PointOfCommunication{
public:
	StarlinkSatellite(string communicatesWith, CommunicationRelay* obj);
	~StarlinkSatellite();
    string getCommunicatesWith();
    StarlinkSatellite* clone();

    StarlinkSatellite* next;
    StarlinkSatellite* previous;
private:
    CommunicationRelay* relay;
    string communicatesWith;
};

#endif