#ifndef STARLINKCOLLECTION_H
#define STARLINKCOLLECTION_H

using namespace std;

#include "StarlinkSatellite.h"
#include "SatelliteManager.h"
#include "Rocketship.h"
#include "SatelliteIterator.h"
#include <vector>
#include "BaseStation.h"
#include "SpaceStation.h"

class SatelliteManager;
class SatelliteIterator;

class StarlinkCollection : public Rocketship {
public:
    StarlinkCollection(string name,BaseStation* BS ,SpaceStation* SS); 
	
    //deallocates everything associated with the StarlinkCollection ,
    //except the : FalconRocket instance
    virtual ~StarlinkCollection();

    void Launch();

    //Used by the Iterator Design Pattern
    void insert(StarlinkSatellite*);
    StarlinkSatellite* remove();
    SatelliteIterator* begin();
    SatelliteIterator* end();
    StarlinkSatellite* getFirstSat();
    
    StarlinkCollection* clone();
    
    void attachRocket(FalconRocket*);

    void setCommunicationRelayBS(CommunicationRelay*);
    void setCommunicationRelaySS(CommunicationRelay*);

    virtual int getRockets();
    virtual bool testFire();
    virtual bool testLoading();

    void setNums(int num_B ,int num_S);
    void setHead(StarlinkSatellite*);

    void setSatellites(int num_B,int num_S);

    //Function used in testing
    bool isViableClone(StarlinkCollection*);

private:

    //set in the StarlinkBay
    int num_B;
    int num_S;
    FalconRocket* rocket;
    
    //Created in Main and assigned in constructor
    BaseStation* BS;
    SpaceStation* SS;

    //created in this class
    SatelliteManager* satelliteManager;

    //Created and assigned in the SatelliteManager
    CommunicationRelay* relayBS;
    CommunicationRelay* relaySS;
    StarlinkSatellite* head;

};

#endif