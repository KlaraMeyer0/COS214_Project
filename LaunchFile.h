#ifndef LAUNCHFILE_H
#define LAUNCHFILE_H

using namespace std;

#include "Rocketship.h"

class LaunchFile {
private:
    Rocketship** rocketships;
public:
	LaunchFile();
	~LaunchFile();
    Rocketship** getLaunch();
    void setLaunch(Rocketship** rocketships);
};

#endif
