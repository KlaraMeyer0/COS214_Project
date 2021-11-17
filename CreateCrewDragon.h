#ifndef CREATECREWDRAGON_H
#define CREATECREWDRAGON_H

using namespace std;

#include "Work.h"
#include "CrewDragonBay.h"

class CreateCrewDragon : public Work {
public:
	CreateCrewDragon();
	~CreateCrewDragon();
	void execute();
	void undo();
};

#endif