#ifndef TESTLAUNCH_H
#define TESTLAUNCH_H

using namespace std;

#include "Work.h"

class TestLaunch : public Work{//Memento client
public:
	TestLaunch();
	~TestLaunch();
    void execute();
    void undo();
};

#endif