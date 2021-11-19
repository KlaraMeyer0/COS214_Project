#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Work.h"
#include "LaunchInterface.h"

class Director
{
public:
    Director();
    ~Director();
    bool makeDragon();
    bool makeCrewDragon();
    bool makeStarlink();
    bool createBackup();
    bool retrieveBackup();
    bool startTestLaunch();
private:
    Work **command;
    LaunchInterface* interface;
};

#endif