#ifndef LAUNCHINTERFACE_H
#define LAUNCHINTERFACE_H

using namespace std;

#include "Rocketship.h"
#include "LaunchCaretaker.h"
#include "Launch.h"
#include "LaunchFile.h"
#include <sstream>

class LaunchInterface {//Memento Originator
public:
	LaunchInterface();
	~LaunchInterface();
	LaunchFile* retrieveLaunchFile();
	void setLaunchFile(LaunchFile*);
	void TestLaunch();
	void addRocketship(Rocketship*);
	void storeFile();
	void restoreFile();
	void outputDesc();
private:
    Rocketship** rocketships;
	LaunchCaretaker* launchCaretaker;
	int rocketCount;//added to help with deleting
};

#endif