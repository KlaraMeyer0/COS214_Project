#ifndef DRAGONSPACECRAFT_H
#define DRAGONSPACECRAFT_H

using namespace std;

#include "Spacecraft.h"

class DragonSpacecraft : public Spacecraft {
public:
	DragonSpacecraft();
	DragonSpacecraft(const DragonSpacecraft &obj);
	~DragonSpacecraft();
};

#endif