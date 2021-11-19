#ifndef CREWDRAGONSPACECRAFT_H
#define CREWDRAGONSPACECRAFT_H

using namespace std;

#include "Spacecraft.h"

class CrewDragonSpacecraft : public Spacecraft {
public:
	CrewDragonSpacecraft(int capacity);
	~CrewDragonSpacecraft();
	Spacecraft* clone();
};

#endif