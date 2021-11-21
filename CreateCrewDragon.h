#ifndef CREATECREWDRAGON_H
#define CREATECREWDRAGON_H

#include "Work.h"
#include "RocketshipEngineer.h"
#include "Station.h"

class CreateCrewDragon : public Work{
public:
	CreateCrewDragon(RocketshipEngineer *e, LaunchInterface *l, CrewDragonBay *cd, BaseStation* s);
	~CreateCrewDragon();
	void execute();
	void undo();
private:
	RocketshipEngineer *engineer;
	LaunchInterface *launch_interface;
	CrewDragonBay *crewdragon_bay;
	BaseStation* base_station;
};

#endif