#include "TestLaunch.h"

TestLaunch::TestLaunch(LaunchInterface* l) : Work(l) {}
TestLaunch::~TestLaunch() {}

void TestLaunch::execute() {
    launch_interface->TestLaunch();
}

void TestLaunch::undo() {}