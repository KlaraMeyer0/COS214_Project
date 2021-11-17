#ifndef LAUNCHINTERFACE_H
#define LAUNCHINTERFACE_H

using namespace std;

#include "Rocketship.h"
#include "LaunchCareTaker.h"
#include "TestLaunch.h"
#include "LaunchFile.h"

class LaunchInterface {
private:
    Rocketship** rocketships;
	LaunchCaretaker** launchCaretakers;
public:
	LaunchInterface();
	~LaunchInterface();
	LaunchFile* retieveLaunchFile();
	void setLaunchFile(LaunchFile*);
	void TestLaunch();
	void addRocketship(Rocketship*);
};

#endif