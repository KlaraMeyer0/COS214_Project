#ifndef ROCKETSHIPENGINEER_H
#define ROCKETSHIPENGINEER_H

using namespace std;

class RocketshipEngineer {
private:
	RocketShipBay* rb;
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
	bool startTestLaunch();
};

#endif