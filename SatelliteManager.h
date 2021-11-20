#ifndef SATELLITEMANAGER_H
#define SATELLITEMANAGER_H
#include "StarlinkSatellite.h"
#include "PointOfCommunication.h"
#include <vector>
using namespace std;

class SatelliteManager {
public:
    //parameter: BaseStation and SpaceStation passed 
	SatelliteManager(Station* BS ,Station* ST);
	~SatelliteManager();

    //Lazy Creation
    vector<StarlinkSatellite*>* getSatellite(int num_B, int num_S);
    
    //Clones the Sattelite manager
    SatelliteManager* clone();

    //getters for Communication relays to enable destruction
    CommunicationRelay* getCommunicationRelayBS();
    CommunicationRelay* getCommunicationRelaySS();
private:
    vector<StarlinkSatellite*>* list;
    StarlinkSatellite* protoBSSatellite;
    StarlinkSatellite* protoSTSatellite;

    CommunicationRelay* relayBS;
    CommunicationRelay* relaySS;
};

#endif