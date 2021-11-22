#include "TestLaunch.h"

TestLaunch::TestLaunch(LaunchInterface* l) {
    interface = l;
}
TestLaunch::~TestLaunch() {}

void TestLaunch::execute() {
    interface->TestLaunch();
}

void TestLaunch::undo() {}