#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Work.h"
#include "LaunchCaretaker.h"

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
    LaunchCaretaker **LaunchCaretakers;
};

#endif