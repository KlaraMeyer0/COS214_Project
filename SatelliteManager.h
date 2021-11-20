#ifndef SATELLITEMANAGER_H
#define SATELLITEMANAGER_H
#include "StarlinkSatellite.h"
#include "PointOfCommunication.h"
#include "StarlinkCollection.h"
#include <vector>
using namespace std;

class SatelliteManager {
public:
    //parameter: BaseStation and SpaceStation passed 
	SatelliteManager(Station* BS ,Station* ST, StarlinkCollection* SC);
	~SatelliteManager();

    //Lazy Creation ,dierctly into the associated StarlinkCollection
    void SatelliteManager:: setSatellites(int num_B, int num_S);
    
    //Clones the Sattelite manager
    SatelliteManager* clone(StarlinkCollection*);

    //getters for Communication relays to enable destruction
    CommunicationRelay* getCommunicationRelayBS();
    CommunicationRelay* getCommunicationRelaySS();

    StarlinkSatellite* getHead();
private:
    StarlinkSatellite* head;
    StarlinkSatellite* protoBSSatellite;
    StarlinkSatellite* protoSTSatellite;

    CommunicationRelay* relayBS;
    CommunicationRelay* relaySS;

    StarlinkCollection* SC;
};

#endif