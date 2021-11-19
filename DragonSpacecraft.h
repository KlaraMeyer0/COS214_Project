#ifndef DRAGONSPACECRAFT_H
#define DRAGONSPACECRAFT_H

using namespace std;

#include "Spacecraft.h"

class DragonSpacecraft : public Spacecraft {
public:
	DragonSpacecraft(int capacity);
	~DragonSpacecraft();
	Spacecraft* clone();
};

#endif