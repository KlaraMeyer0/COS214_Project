#ifndef LAUNCHINTERFACE_H
#define LAUNCHINTERFACE_H

using namespace std;

#include "Rocketship.h"

class LaunchInterface {
private:
    Rocketship** rocketships;
public:
	LaunchInterface();
	~LaunchInterface();
};

#endif