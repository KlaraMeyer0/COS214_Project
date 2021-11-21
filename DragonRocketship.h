#ifndef DRAGONROCKETSHIP_H
#define DRAGONROCKETSHIP_H

using namespace std;

#include "Rocketship.h"
#include "Equipment.h"
#include "DragonSpacecraft.h"

class DragonRocketship : public Rocketship
{
public:
    DragonRocketship(string n);
    ~DragonRocketship();
    void Launch();
    Rocketship *clone();
    void attachSpacecraft(Spacecraft *s);
    void attachRocket(FalconRocket *r);
    void attachCargo(vector<Cargo*>);
    Cargo *dropCargo(); // might change -->drops cargo at SpaceStation
    virtual int getRockets();
    virtual bool testFire();
    virtual bool testLoading();
private:
    Cargo **cargo;
    Spacecraft *spacecraft;
    FalconRocket *rocket;
};

#endif