#ifndef LAUNCHINTERFACE_H
#define LAUNCHINTERFACE_H

using namespace std;

#include "Rocketship.h"
#include "LaunchCareTaker.h"
#include "TestLaunch.h"

class LaunchInterface {
private:
    Rocketship** rocketships;
	LaunchCareTaker** launchCareTaker;
public:
	LaunchInterface();
	~LaunchInterface();
	LaunchFile* retieveLaunchFile();
	void setLaunchFile(LaunchFile*);
	void TestLaunch();
	void addRocketship(Rocketship*);
};

#endif