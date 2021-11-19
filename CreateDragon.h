#ifndef CREATEDRAGON_H
#define CREATEDRAGON_H

#include "Work.h"
#include "RocketshipEngineer.h"

class CreateDragon : public Work {
public:
	CreateDragon(RocketshipEngineer *e, LaunchInterface *l, DragonBay *d);
	~CreateDragon();
	void execute();
	void undo();
private:
	RocketshipEngineer *engineer;
	LaunchInterface *launch_interface;
	DragonBay *dragon_bay;
};

#endif