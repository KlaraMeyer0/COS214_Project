#ifndef CREWDRAGONROCKETSHIP_H
#define CREWDRAGONROCKETSHIP_H

using namespace std;

#include "Rocketship.h"
#include "Cargo.h"
#include "Spacecraft.h"

class CrewDragonRocketship : public Rocketship
{
public:
    CrewDragonRocketship(string n);
    ~CrewDragonRocketship();
    void Launch();
    Rocketship *clone();
    void attachSpacecraft(Spacecraft *s);
    void attachRocket(FalconRocket *r);
    void attachCargo(Cargo **c, int size);
    Cargo *dropCargo();
    virtual FalconRocket* getRocket()
private:
    Cargo **cargo;
    Spacecraft *spacecraft;
    FalconRocket *rocket;
};

#endif