#ifndef CREATEDRAGON_H
#define CREATEDRAGON_H

using namespace std;

#include "Work.h"
#include "DragonBay.h"

class CreateDragon : public Work {
public:
	CreateDragon();
	~CreateDragon();
	void execute();
	void undo();
};

#endif