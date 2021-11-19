#ifndef CREWDRAGONFACTORY_H
#define CREWDRAGONFACTORY_H

using namespace std;

#include "SpacecraftFactory.h"

class CrewDragonFactory : public SpacecraftFactory {
public:
	CrewDragonFactory();
	~CrewDragonFactory();
protected:
    Spacecraft* createRocket();
};

#endif