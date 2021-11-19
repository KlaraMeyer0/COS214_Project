#ifndef CREATESTARLINK_H
#define CREATESTARLINK_H

#include "Work.h"
#include "RocketshipEngineer.h"

class CreateStarlink : public Work{
public:
	CreateStarlink(RocketshipEngineer *e, LaunchInterface *l, StarlinkBay *s);
	~CreateStarlink();
	void execute();
	void undo();
private:
	RocketshipEngineer *engineer;
	LaunchInterface *launch_interface;
	StarlinkBay *starlink_bay;
};

#endif