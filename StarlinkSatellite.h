#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H
#include "PointOfCommunication.h"
#include "CommunicationRelay.h"
#include <string>
using namespace std;


class StarlinkSatellite : public PointOfCommunication{
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
    CommunicationRelay* relay;
    string communicatesWith;

    StarlinkSatellite* next;
    StarlinkSatellite* previous;
};

#endif