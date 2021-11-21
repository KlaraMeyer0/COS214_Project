#ifndef CREATEDRAGON_H
#define CREATEDRAGON_H

#include "Work.h"
#include "RocketshipEngineer.h"
#include "Station.h"

class CreateDragon : public Work {
public:
	CreateDragon(RocketshipEngineer *e, LaunchInterface *l, DragonBay *d, BaseStation *s);
	virtual ~CreateDragon();
	void execute();
	void undo();
private:
	RocketshipEngineer *engineer;
	LaunchInterface *launch_interface;
	DragonBay *dragon_bay;
	BaseStation* base_station;
};

#endif