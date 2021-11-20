#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Work.h"
#include "LaunchInterface.h"
#include "RocketshipEngineer.h"
#include "CreateCrewDragon.h"
#include "CreateDragon.h"
#include "CreateStarlink.h"
#include "Backup.h"
#include "TestLaunch.h"
#include "OrderCargo.h"

class Director
{
public:
    Director(LaunchInterface *i, BaseStation *b);
    ~Director();
    void makeDragon();
    void makeCrewDragon();
    void makeStarlink();
    void createBackup();
    void retrieveBackup();
    void startTestLaunch();
    void receiveCargo();

private:
    Work **command;
    LaunchInterface *interface;
    RocketshipEngineer *engineer;
    CrewDragonBay *crewdragon_Bay;
    DragonBay *dragon_Bay;
    StarlinkBay *starlink_Bay;
    BaseStation *base_station;
};

#endif