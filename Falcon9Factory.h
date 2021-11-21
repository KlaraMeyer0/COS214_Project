#ifndef FALCON9FACTORY_H
#define FALCON9FACTORY_H

using namespace std;

#include "RocketFactory.h"

class Falcon9Factory : public RocketFactory {
public:
	Falcon9Factory();
	virtual ~Falcon9Factory();
protected:
    FalconRocket* createRocket();
};

#endif