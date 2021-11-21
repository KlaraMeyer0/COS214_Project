#ifndef LAUNCH_H
#define LAUNCH_H

#include "Rocketship.h"

using namespace std;

class Launch {
public:
	virtual void startLaunch() = 0;
	bool getType(){
		return t;
	}
	virtual Rocketship* getShip() = 0; 
protected:
	bool t;
};

#endif