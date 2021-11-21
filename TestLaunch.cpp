#include "TestLaunch.h"

TestLaunch::TestLaunch(LaunchInterface* l) {
    this->l = l;
}
TestLaunch::~TestLaunch() {}

void TestLaunch::execute() {
    l->TestLaunch();
}

void TestLaunch::undo() {}