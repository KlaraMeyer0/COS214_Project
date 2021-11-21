#ifndef LAUNCHFILE_H
#define LAUNCHFILE_H

using namespace std;

#include "Rocketship.h"

class LaunchFile {//Memento
private:
    Rocketship** rocketships;
    int count;
public:
	LaunchFile();
	virtual ~LaunchFile();
    Rocketship** getLaunch();
    void setLaunch(Rocketship** rocketships,int c);
    int getCount();
};

#endif
