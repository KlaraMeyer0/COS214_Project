#include "Director.h"

Director::Director(LaunchInterface *i)
{
    interface = i;
    crewdragon_Bay = new CrewDragonBay();
    dragon_Bay = new DragonBay();
    starlink_Bay = new StarlinkBay();
    engineer = new RocketshipEngineer(crewdragon_Bay, dragon_Bay, starlink_Bay);
    command = new Work *[5];
    command[0] = new CreateCrewDragon(engineer, interface, crewdragon_Bay);
    command[1] = new CreateDragon(engineer, interface, dragon_Bay);
    command[2] = new CreateStarlink(engineer, interface, starlink_Bay);
    command[3] = new Backup(interface);
    command[4] = new TestLaunch();
}
Director::~Director()
{
    delete interface;
    for (int i = 0; i < 5; i++)
        delete command[i];
    delete[] command;
    delete crewdragon_Bay;
    delete dragon_Bay;
    delete starlink_Bay;
    delete engineer;
}

bool Director::makeCrewDragon()
{
    command[0]->execute();
}

bool Director::makeDragon()
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