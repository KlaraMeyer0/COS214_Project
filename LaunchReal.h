#ifndef LAUNCHREAL_H
#define LAUNCHREAL_H

#include "Rocketship.h"
#include "Launch.h"

using namespace std;

class LaunchReal : public Launch{
private:
    Rocketship* ship;
public:
	LaunchReal(Rocketship*);
	virtual ~LaunchReal();
    virtual void startLaunch();
    virtual Rocketship* getShip();
};

#endif