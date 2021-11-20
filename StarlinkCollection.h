#ifndef STARLINKCOLLECTION_H
#define STARLINKCOLLECTION_H

using namespace std;

#include "StarlinkSatellite.h"
#include "SatelliteManager.h"
#include "Rocketship.h"
#include "FalconRocket.h"
#include "SatelliteIterator.h"
#include <vector>
#include "BaseStation.h"
#include "SpaceStation.h"

class StarlinkCollection : public Rocketship {
public:
    //Luca->Klara: is this OK ? sets the BaseStation and SpaceStation automatically
    StarlinkCollection(string name); //Talk to me ~ Xander
	
    //deallocates everuthing associated with the StarlinkCollection ,
    //except the : FalconRocket instance
    ~StarlinkCollection();

    void Launch();

    //Used by the Iterator Design Pattern
    void insert(StarlinkSatellite*);
    StarlinkSatellite* remove();
    SatelliteIterator* begin();
    SatelliteIterator* end();
    StarlinkSatellite* getFirstSat();
    
    StarlinkCollection* clone();
    StarlinkSatellite* getHead();

    void setCommunicationRelayBS(CommunicationRelay*);
    void setCommunicationRelaySS(CommunicationRelay*);

private:
    FalconRocket* rocket;
    int numSatellites;
    SatelliteManager* satelliteManager;
    int num_B;
    int num_S;
    StarlinkSatellite* head;

    //Created in StarlinkCollection
    Station* BS;
    Station* SS;

    //Created and assigned in the SatelliteManager
    CommunicationRelay* relayBS;
    CommunicationRelay* relaySS;

};

#endif