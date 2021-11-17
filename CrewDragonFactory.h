#ifndef CREWDRAGONFACTORY_H
#define CREWDRAGONFACTORY_H

using namespace std;

#include "SpacecraftFactory.h"

class CrewDragonFactory : public SpacecraftFactory {
private:
    Spacecraft* spacecraft;
public:
	CrewDragonFactory();
	~CrewDragonFactory();
    Spacecraft* createRocket();
};

#endif