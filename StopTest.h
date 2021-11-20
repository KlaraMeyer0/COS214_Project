#ifndef STOPTEST_H
#define STOPTEST_H

using namespace std;

#include "LaunchTest.h"
#include <iostream>

class StopTest : public LaunchTest {
public:
	StopTest(Launch*);
	~StopTest();
    void output();
	virtual void startLaunch();
private:
	bool flag;
};

#endif