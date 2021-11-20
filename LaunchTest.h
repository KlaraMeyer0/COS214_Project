#ifndef LAUNCHTEST_H
#define LAUNCHTEST_H

using namespace std;

#include "Launch.h"
#include <iostream>

class LaunchTest : public Launch {
public:
	LaunchTest(Launch* la){
		l = la;
		t = false;
	};
	virtual ~LaunchTest(){
		delete l;
	};
    virtual void output() = 0;
	virtual void startLaunch() = 0;
	virtual Rocketship* getShip(){
		return l->getShip();
	};
protected:
	Launch* l;
};

#endif