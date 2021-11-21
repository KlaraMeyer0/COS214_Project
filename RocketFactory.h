#ifndef ROCKETFACTORY_H
#define ROCKETFACTORY_H

#include "FalconRocket.h"

class RocketFactory {
public:
	RocketFactory();
	virtual ~RocketFactory();
    FalconRocket* startFactory();
protected:
    virtual FalconRocket* createRocket() = 0;
private:
    FalconRocket* fr;
};

#endif