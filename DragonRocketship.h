#ifndef DRAGONROCKETSHIP_H
#define DRAGONROCKETSHIP_H

using namespace std;

#include "Rocketship.h"
#include "FalconHeavy.h"
#include "Cargo.h"
#include "Spacecraft.h"

class DragonRocketship : public Rocketship {
private:
    Cargo* cargo;
    Spacecraft* spacecraft;
    FalconHeavy* rocket;
public:
	DragonRocketship();
	~DragonRocketship();
    void Launch();
};

#endif