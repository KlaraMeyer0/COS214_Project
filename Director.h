#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Work.h"
#include "LaunchCaretaker.h"

class Director
{
private:
    Work **command;
    LaunchCaretaker **LaunchCaretakers;

public:
    Director();
    ~Director();
    bool makeDragon();
    bool makeCrewDragon();
    bool makeStarlink();
    bool createBackup();
    bool retrieveBackup();
    bool startTestLaunch();
};

#endif