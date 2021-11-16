#ifndef COMMUNICATIONRELAY_H
#define COMMUNICATIONRELAY_H

using namespace std;

#include <vector>
#include "StarlinkSatellite.h"

class CommunicationRelay {
private:
    vector<bool> SatStatus;
    vector<> logs;
public:
	CommunicationRelay();
	~CommunicationRelay();
    void notify(StarlinkSatellite*);
};

#endif