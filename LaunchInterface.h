#ifndef LAUNCHINTERFACE_H
#define LAUNCHINTERFACE_H

using namespace std;

#include "Rocketship.h"
#include "LaunchCareTaker.h"
#include "TestLaunch.h"
#include "LaunchFile.h"

class LaunchInterface {//Memento Originator
public:
	LaunchInterface();
	~LaunchInterface();
	LaunchFile* retrieveLaunchFile();
	void setLaunchFile(LaunchFile*);
	void TestLaunch();
	void addRocketship(Rocketship*);
	void storeFile(LaunchFile*);
	void getFile();//?
private:
    Rocketship** rocketships;
	LaunchCaretaker* launchCaretaker;
	int rocketCount;//added to help with deleting
};

#endif