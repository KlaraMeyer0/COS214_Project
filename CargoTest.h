#ifndef CARGOTEST_H
#define CARGOTEST_H

using namespace std;

#include "LaunchTest.h"

class CargoTest : public LaunchTest{
public:
	CargoTest(Launch*);
	~CargoTest();
    void output();
	virtual void startLaunch();
	
};

#endif