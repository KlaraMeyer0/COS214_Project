#ifndef ENGINEPRESENTTEST_H
#define ENGINEPRESENTTEST_H

using namespace std;

#include "LaunchTest.h"

class EnginePresentTest : public LaunchTest {
public:
	EnginePresentTest();
	~EnginePresentTest();
    void output();
	virtual void startLaunch();
	void add(Launch*);
};

#endif