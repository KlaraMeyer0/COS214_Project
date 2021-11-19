#ifndef COMMUNICATIONRELAY_H
#define COMMUNICATIONRELAY_H

using namespace std;

#include <vector>
#include "StarlinkSatellite.h"
#include "Station.h"
#include "map"

class CommunicationRelay {
private:
    map<int ,bool> SatStatus;
    Station* RelayTo;
    vector<StarlinkSatellite*> satellites;
    int numSats;
public:
	CommunicationRelay(Station*,int);
	~CommunicationRelay();
    void notify(StarlinkSatellite*);
    void addSatellite(StarlinkSatellite*);
};

#endif