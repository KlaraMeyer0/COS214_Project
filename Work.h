#ifndef WORK_H
#define WORK_H

using namespace std;
#include "LaunchInterface.h"

class Work {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

#endif