#include "TestLaunch.h"

TestLaunch::TestLaunch(LaunchInterface* l) : Work(l) {}
TestLaunch::~TestLaunch() {}

void TestLaunch::execute() {
    launch_interface->TestLaunch();
}

void TestLaunch::undo() {
    Rocketship** rockets = launch_interface->getAllRockets();
    for (int i=0; i<launch_interface->getRocketCount(); i++)
    {
        if (rockets[i]->getStation()->getName() != "Base-KJLXR-28564")
        {
            rockets[i]->startLanding(launch_interface->getBaseStation());
        }
    }
}