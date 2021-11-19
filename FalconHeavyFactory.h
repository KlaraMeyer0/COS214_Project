#ifndef FALCONHEAVYFACTORY_H
#define FALCONHEAVYFACTORY_H

using namespace std;

#include "RocketFactory.h"

class FalconHeavyFactory : public RocketFactory {
public:
	FalconHeavyFactory();
	~FalconHeavyFactory();
protected:
    FalconRocket* createRocket();
};

#endif