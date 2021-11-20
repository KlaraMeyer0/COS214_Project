#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H
#include "PointOfCommunication.h"
#include "CommunicationRelay.h"
#include <string>
using namespace std;

//Participant: 
//Colleague in Mediator ,ConcretePrototype in Prototyep Pattern
//ConcreteAggregate in the Iterator 
class StarlinkSatellite : public PointOfCommunication{
public:
    //Must passed a Communicationrelay that serves as the Mediator participant
	StarlinkSatellite(string communicatesWith, CommunicationRelay* obj);
	~StarlinkSatellite();
    string getCommunicatesWith();

    //Used by the prototype pattern
    StarlinkSatellite* clone();

    //Used in the Iterator Pattern
    StarlinkSatellite* next;
    StarlinkSatellite* previous;
private:
    CommunicationRelay* relay;
    string communicatesWith;
};

#endif