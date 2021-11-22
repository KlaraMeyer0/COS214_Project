/**
 * @file CrewDragonRocketship.h
 * @author your name (you@domain.com)
 * @brief 
 * Design Pattern: 
 * Participant: 
 * 
 */
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
    virtual ~CrewDragonRocketship();
    void Launch();
    Rocketship *clone();
    void attachSpacecraft(Spacecraft *s);
    void attachRocket(FalconRocket *r);
    void attachCargo(vector<Cargo *>);
    Cargo *dropCargo();
    virtual int getRockets();
    virtual bool testFire();
    virtual bool testLoading();
private:
    Cargo **cargo;
    Spacecraft *spacecraft;
    FalconRocket *rocket;
};

#endif