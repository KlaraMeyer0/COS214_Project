#ifndef ENGINEPRESENTTEST_H
#define ENGINEPRESENTTEST_H

using namespace std;

#include "LaunchTest.h"

class EnginePresentTest : public LaunchTest {
public:
	EnginePresentTest(Launch*);
	~EnginePresentTest();
    void output();
	virtual void startLaunch();
};

#endif