#ifndef ROCKETFACTORY_H
#define ROCKETFACTORY_H

using namespace std;

#include "FalconRocket.h"

class RocketFactory {
private:
    FalconRocket* fr;
public:
	RocketFactory();
	~RocketFactory();
    virtual FalconRocket* createRocket() = 0;
    FalconRocket* startFactory();
};

#endif