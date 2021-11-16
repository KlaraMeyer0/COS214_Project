#ifndef LAUNCHTEST_H
#define LAUNCHTEST_H

using namespace std;

#include "Launch.h"

class LaunchTest : public Launch {
public:
	LaunchTest();
	~LaunchTest();
    virtual void output() = 0;
};

#endif