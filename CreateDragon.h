#ifndef CREATEDRAGON_H
#define CREATEDRAGON_H

#include "Work.h"
#include "RocketshipEngineer.h"
#include "Station.h"

class CreateDragon : public Work {
public:
	CreateDragon(RocketshipEngineer *e, LaunchInterface *l, DragonBay *d, Station *s);
	~CreateDragon();
	void execute();
	void undo();
private:
	RocketshipEngineer *engineer;
	LaunchInterface *launch_interface;
	DragonBay *dragon_bay;
	Station* base_station;
};

#endif