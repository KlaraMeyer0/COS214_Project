#include "TestLaunch.h"

TestLaunch::TestLaunch(LaunchInterface* l) {
    launch_interface = l;
}
TestLaunch::~TestLaunch() {}

void TestLaunch::execute() {
    launch_interface->TestLaunch();
}

void TestLaunch::undo() {}