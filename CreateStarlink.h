#ifndef CREATESTARLINK_H
#define CREATESTARLINK_H

#include "Work.h"
#include "RocketshipEngineer.h"
#include "Station.h"

class CreateStarlink : public Work{
public:
	CreateStarlink(RocketshipEngineer *e, LaunchInterface *l, StarlinkBay *s, BaseStation *b, SpaceStation* ss);
	virtual ~CreateStarlink();
	void execute();
	void undo();
private:
	RocketshipEngineer *engineer;
	LaunchInterface *launch_interface;
	StarlinkBay *starlink_bay;
	BaseStation* base_station;
	SpaceStation* space_station;
};

#endif