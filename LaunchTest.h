#ifndef LAUNCHTEST_H
#define LAUNCHTEST_H

using namespace std;

#include "Launch.h"

class LaunchTest : public Launch {
public:
	LaunchTest();
	virtual ~LaunchTest();
	virtual void add(Launch*) = 0;
    virtual void output() = 0;
	virtual void startLaunch() = 0;
};

#endif