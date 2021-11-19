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

class Director
{
public:
    Director(LaunchInterface *i);
    ~Director();
    bool makeDragon();
    bool makeCrewDragon();
    bool makeStarlink();
    bool createBackup();
    bool retrieveBackup();
    bool startTestLaunch();

private:
    Work **command;
    LaunchInterface *interface;
    RocketshipEngineer *engineer;
};

#endif