#ifndef ROCKETSHIPENGINEER_H
#define ROCKETSHIPENGINEER_H

#include "Work.h"
#include "RocketShipBay.h"
#include "LaunchCaretaker.h"

class RocketshipEngineer {
private:
	RocketshipBay* rb;
	Work** command;
	LaunchCaretaker** LaunchCaretakers;
public:
	RocketshipEngineer();
	~RocketshipEngineer();
	void construct();
	bool makeDragon();
	bool makeCrewDragon();
	bool makeStarlink();
	bool createBackup();
	bool retrieveBackup();
	bool startTestLaunch();
};

#endif