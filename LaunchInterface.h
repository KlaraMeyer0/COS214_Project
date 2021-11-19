#ifndef LAUNCHINTERFACE_H
#define LAUNCHINTERFACE_H

using namespace std;

#include "Rocketship.h"
#include "LaunchCareTaker.h"
#include "TestLaunch.h"
#include "LaunchFile.h"

class LaunchInterface {//Memento Originator
private:
    Rocketship** rocketships;
	LaunchCaretaker* launchCaretakers;
	int rocketCount;//added to help with deleting
public:
	LaunchInterface();
	~LaunchInterface();
	LaunchFile* retieveLaunchFile();
	void setLaunchFile(LaunchFile*);
	void TestLaunch();
	void addRocketship(Rocketship*);
};

#endif