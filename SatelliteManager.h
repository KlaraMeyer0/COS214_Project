#ifndef SATELLITEMANAGER_H
#define SATELLITEMANAGER_H
#include "StarlinkSatellite.h"
#include "PointOfCommunication.h"
#include "StarlinkCollection.h"
#include <vector>
using namespace std;

class SatelliteManager {
public:
    
	SatelliteManager(BaseStation* BS ,SpaceStation* ST, StarlinkCollection* SC);
	
    //deletes the prototypical insntaces and removes the 
    //associations between this class and all other classes 
    ~SatelliteManager();

    //Lazy Creation ,dierctly into the associated StarlinkCollection
    void setSatellites(int num_B, int num_S);
    
    //Clones the Sattelite manager, if called will not have to call setSatellites(...)
    SatelliteManager* clone(StarlinkCollection*,BaseStation* BScopy ,SpaceStation* SScopy);

    //getters for Communication relays to enable destruction
    CommunicationRelay* getCommunicationRelayBS();
    CommunicationRelay* getCommunicationRelaySS();

    StarlinkSatellite* getHead();
private:

    //set after creation in this class
    StarlinkSatellite* head;
    
    //set in creation of this class
    StarlinkSatellite* protoBSSatellite;
    StarlinkSatellite* protoSTSatellite;
    CommunicationRelay* relayBS;
    CommunicationRelay* relaySS;

    //passed to this class in the Constructor
    StarlinkCollection* SC;
    BaseStation* BS;
    SpaceStation* SS;
};

#endif