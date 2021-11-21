/**
 * @file LaunchInterface.h
 * @author James Butler
 * @brief 
 * 
 * Design Pattern: Memento
 * Participant: Originator
 */
#ifndef LAUNCHINTERFACE_H
#define LAUNCHINTERFACE_H

#include "Rocketship.h"
#include "LaunchCaretaker.h"
#include "LaunchReal.h"
#include "EnginePresentTest.h"
#include "EngineFireTest.h"
#include "StopTest.h"
#include "CargoTest.h"
#include "LaunchFile.h"
#include <sstream>

using namespace std;

class LaunchInterface {
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
	int rocketCount;
};

#endif