#ifndef COMMUNICATIONRELAY_H
#define COMMUNICATIONRELAY_H

using namespace std;

#include <vector>
#include "StarlinkSatellite.h"
#include "Station.h"

class CommunicationRelay {
private:
    vector<bool> SatStatus;
    //vector<> logs;
    int size;
    vector<Station*> RelayTo;
    vector<Station*> RelayTo2;
public:
	CommunicationRelay();
	~CommunicationRelay();
    void notify(StarlinkSatellite*, int);
    void addRelay(Station*);
};

#endif