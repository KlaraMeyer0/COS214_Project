#ifndef LAUNCHREAL_H
#define LAUNCHREAL_H

using namespace std;

#include "Rocketship.h"

class LaunchReal {
private:
    Rocketship* ship;
public:
	LaunchReal();
	~LaunchReal();
    void startLaunch();
};

#endif