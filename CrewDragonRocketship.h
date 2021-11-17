#ifndef CREWDRAGONROCKETSHIP_H
#define CREWDRAGONROCKETSHIP_H

using namespace std;

#include "Rocketship.h"
#include "FalconRocket.h"
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