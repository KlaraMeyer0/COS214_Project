#ifndef ENGINEFIRETEST_H
#define ENGINEFIRETEST_H

using namespace std;

#include "LaunchTest.h"

class EngineFireTest : public LaunchTest {
public:
	EngineFireTest(Launch*);
	~EngineFireTest();
    void output();
	virtual void startLaunch(); 
};

#endif