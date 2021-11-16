#ifndef CREATESTARLINK_H
#define CREATESTARLINK_H

using namespace std;

#include "Work.h"
#include "StarlinkBay.h"

class CreateStarlink : public Work {
public:
	CreateStarlink();
	~CreateStarlink();
	void execute();
	void undo();
};

#endif