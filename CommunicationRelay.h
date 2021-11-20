#ifndef COMMUNICATIONRELAY_H
#define COMMUNICATIONRELAY_H
#include <vector>
#include "StarlinkSatellite.h"
#include "Station.h"
#include "map"
using namespace std;

//Prticipant: ConcreteMediator in the Mediator pattern


class CommunicationRelay {
private:
    //Associates a colleague with a status value 
    //this attribute is dulpicated in Station, is this redundant
    map<int ,bool> SatStatus;

    //Colleague that is communicated with: Station
    Station* RelayTo;
    int numSats;

    //the StarlinkSattellite communicating with the Station: RelayTo
    vector<StarlinkSatellite*> sattelites;

public:
    
    //Constructor to set the RelayTo colleague 
	CommunicationRelay(Station*);

    //Disconencts it from the StarlinkSatellite it is associated with 
	~CommunicationRelay();

    //used to notify the Station of any changes ,made to the Sattellite
    void notify(StarlinkSatellite*);

    //used to track a colleauge 
    void addSatellite(StarlinkSatellite*);

    //used by a Station to update the Status of a StarlinkSattellite
    void reslove(StarlinkSatellite*);
};

#endif