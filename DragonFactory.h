#ifndef DRAGONFACTORY_H
#define DRAGONFACTORY_H

using namespace std;

#include "SpacecraftFactory.h"

class DragonFactory : public SpacecraftFactory {
private:
    Spacecraft* spacecraft;
public:
	DragonFactory();
	~DragonFactory();
    Spacecraft* createRocket();
};

#endif