#ifndef STARLINKSATELLITE_CPP
#define STARLINKSATELLITE_CPP
#include "StarlinkSatellite.h"
using namespace std;


	StarlinkSatellite(string, CommunicationRelay*);//talk to me (Xander) when you are done/starting with this such that I can update the Factory Method
	~StarlinkSatellite();
    void setStatus();
    string getCommunicatesWith();
    bool getStatus();
    StarlinkSatellite* clone();
    void setName(int);

    CommunicationRelay* relay;
    string communicatesWith;
    StarlinkSatellite* next;
    StarlinkSatellite* previous;

#endif