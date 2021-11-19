#include "Director.h"

Director::Director(LaunchInterface *i)
{
    interface = i;
    command = new Work *[5];
    command[0] = new CreateDragon();
    command[1] = new CreateCrewDragon();
    command[2] = new CreateStarlink();
    command[3] = new Backup(interface);
    command[4] = new TestLaunch();
}
Director::~Director()
{
    delete interface;
}

bool Director::makeDragon()
{
    command[0]->execute();
}

bool Director::makeCrewDragon()
{
    command[1]->execute();
}

bool Director::makeStarlink()
{
    command[2]->execute();
}

bool Director::createBackup()
{
    command[3]->execute();
}

bool Director::retrieveBackup()
{
    command[3]->undo();
}

bool Director::startTestLaunch()
{
    command[4]->execute();
}