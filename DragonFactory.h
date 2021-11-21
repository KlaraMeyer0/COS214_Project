#ifndef DRAGONFACTORY_H
#define DRAGONFACTORY_H

using namespace std;

#include "SpacecraftFactory.h"

class DragonFactory : public SpacecraftFactory {
public:
	DragonFactory();
	virtual ~DragonFactory();
protected:
    Spacecraft* createRocket();
};

#endif