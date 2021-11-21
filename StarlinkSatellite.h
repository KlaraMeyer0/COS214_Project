#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

using namespace std;

#include "PointOfCommunication.h"
#include "CommunicationRelay.h"
#include <string>


class CommunicationRelay;
//Participant: 
//Colleague in Mediator ,ConcretePrototype in Prototyep Pattern
//ConcreteAggregate in the Iterator 

class StarlinkSatellite : public PointOfCommunication{
public:
    //Must pass a CommunicationRelay that serves as the Mediator participant
	StarlinkSatellite(string communicatesWith, CommunicationRelay* obj);
	~StarlinkSatellite();
    string getCommunicatesWith();

    //Used by the prototype pattern
    StarlinkSatellite* clone();
    StarlinkSatellite* cloneExact(string communicatesWith, CommunicationRelay* obj);

    //Used in the Iterator Pattern
    StarlinkSatellite* next;
    StarlinkSatellite* previous;

private:
    CommunicationRelay* relay;
    string communicatesWith;
};

#endif