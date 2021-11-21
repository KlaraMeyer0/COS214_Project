#include <limits.h>
#include <stdexcept>
#include <iostream>

using namespace std;

//#include "gtest/gtest.h"
#include "BaseStation.h"
#include "SpaceStation.h"
#include "Human.h"
#include "Equipment.h"

namespace
{
    // Tests chain of responsibility
    void runChainOfResponsibilityTests()
    {
        Station* testStation = new BaseStation();
        testStation->add(new SpaceStation());

        testStation->receiveCargo()
    }
}
