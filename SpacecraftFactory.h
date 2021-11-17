#ifndef SPACECRAFTFACTORY_H
#define SPACECRAFTFACTORY_H

using namespace std;

#include "Spacecraft.h"

class SpacecraftFactory {
private:
    Spacecraft* spacecraft;
public:
	SpacecraftFactory();
	~SpacecraftFactory();
    virtual Spacecraft* createRocket() = 0;
    Spacecraft* startFactory();
};

#endif