#include "RocketshipEngineer.h"

RocketshipEngineer::RocketshipEngineer() {}
RocketshipEngineer::~RocketshipEngineer() {}

void RocketshipEngineer::construct()
{
    rb->buildBody();
    rb->addCargo();
    rb->buildRocket();
}

bool RocketshipEngineer::makeDragon() {}

bool RocketshipEngineer::makeCrewDragon() {}

bool RocketshipEngineer::makeStarlink() {}

bool RocketshipEngineer::createBackup() {}

bool RocketshipEngineer::retrieveBackup() {}

bool RocketshipEngineer::startTestLaunch() {}