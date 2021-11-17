#ifndef TESTLAUNCH_H
#define TESTLAUNCH_H

using namespace std;

#include "Launch.h"

class TestLaunch {
public:
	TestLaunch();
	~TestLaunch();
    void execute();
    void undo();
};

#endif