#ifndef DRAGONROCKETSHIP_H
#define DRAGONROCKETSHIP_H

using namespace std;

#include "Rocketship.h"
#include "FalconHeavy.h"
#include "Equipment.h"
#include "DragonSpacecraft.h"

class DragonRocketship : public Rocketship
{
public:
    DragonRocketship();
    ~DragonRocketship();
    void Launch();
    Rocketship *clone();
    void attachSpacecraft(Spacecraft *s);
    void attachRocket(FalconRocket *r);
    void attachCargo(Cargo **c, int size);
    Cargo *dropCargo();

private:
    Cargo **cargo;
    Spacecraft *spacecraft;
    FalconRocket *rocket;
};

#endif