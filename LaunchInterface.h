#ifndef LAUNCHINTERFACE_H
#define LAUNCHINTERFACE_H

using namespace std;

#include "Rocketship.h"
#include "LaunchCaretaker.h"
#include "LaunchReal.h"
#include "EnginePresentTest.h"
#include "EngineFireTest.h"
#include "StopTest.h"
#include "CargoTest.h"
#include "LaunchFile.h"
#include <sstream>

class LaunchInterface {//Memento Originator
public:
	LaunchInterface();
	virtual ~LaunchInterface();
	LaunchFile* retrieveLaunchFile();
	void setLaunchFile(LaunchFile*);
	void TestLaunch();
	void addRocketship(Rocketship*);
	void storeFile();
	void restoreFile();
	void outputDesc();
	void getDesc();
private:
    Rocketship** rocketships;
	LaunchCaretaker* launchCaretaker;
	int rocketCount;//added to help with deleting
};

#endif