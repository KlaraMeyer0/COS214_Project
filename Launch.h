#ifndef LAUNCH_H
#define LAUNCH_H

using namespace std;

class Launch {
public:
	Launch();
	~Launch();
	virtual void startLaunch() = 0;
};

#endif