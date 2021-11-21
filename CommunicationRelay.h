#ifndef COMMUNICATIONRELAY_H
#define COMMUNICATIONRELAY_H
#include <vector>
#include "StarlinkSatellite.h"
#include "Station.h"
#include "map"
using namespace std;

//Prticipant: ConcreteMediator in the Mediator pattern
class StarlinkSatellite;
class Station;

class CommunicationRelay {
public:
    
    //Constructor to set the RelayTo colleague 
	CommunicationRelay(Station*);

    //Disconnects it from the StarlinkSatellite it is associated with
virtual	~CommunicationRelay();

    //used to notify the Station of any changes ,made to the Satellite
    void notify(StarlinkSatellite*);

    //used to track a colleague
    void addSatellite(StarlinkSatellite*);

    //used by a Station to update the Status of a StarlinkSatellite
    void resolve(StarlinkSatellite*);

    CommunicationRelay* clone(Station*);

    map<int ,bool> getStatStatus();

private:
    //Associates a colleague with a status value 
    //this attribute is duplicated in Station
    map<int ,bool> SatStatus;

    //Colleague that is communicated with: Station
    Station* RelayTo;

    //the StarlinkSatellite communicating with the Station: RelayTo
    vector<StarlinkSatellite*> satellites;

};

#endif