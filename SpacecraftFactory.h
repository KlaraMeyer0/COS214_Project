#ifndef SPACECRAFTFACTORY_H
#define SPACECRAFTFACTORY_H

#include "Spacecraft.h"

class SpacecraftFactory {
public:
	SpacecraftFactory();
	virtual ~SpacecraftFactory();
    Spacecraft* startFactory();
protected:
    virtual Spacecraft* createRocket() = 0;
};

#endif