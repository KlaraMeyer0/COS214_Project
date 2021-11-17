#ifndef LAUNCHFILE_H
#define LAUNCHFILE_H

using namespace std;

#include "State.h"

class LaunchFile {
private:
    State state;
public:
	LaunchFile();
	~LaunchFile();
    State getState();
    void setState(State);
};

#endif