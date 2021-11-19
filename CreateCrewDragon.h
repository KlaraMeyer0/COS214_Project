#ifndef CREATECREWDRAGON_H
#define CREATECREWDRAGON_H

#include "Work.h"
#include "RocketshipEngineer.h"

class CreateCrewDragon : public Work{
public:
	CreateCrewDragon(RocketshipEngineer *e, LaunchInterface *l, CrewDragonBay *cd);
	~CreateCrewDragon();
	void execute();
	void undo();
private:
	RocketshipEngineer *engineer;
	LaunchInterface *launch_interface;
	CrewDragonBay *crewdragon_bay;
};

#endif