#include <limits.h>
#include <stdexcept>
#include <iostream>

using namespace std;

//#include "gtest/gtest.h"
#include "Cargo.h"
#include "ConcreteCargohandler.h"

namespace
{
    // Tests chain of responsibility
    void runChainOfResponsibilityTests()
    {
        Cargo* testCargo1 = new Cargo("Pete", true);
        Cargo* testCargo2 = new Cargo("Rope", false);
        Cargo* testCargo3 = new Cargo("Kate", true);
        Cargo* testCargo4 = new Cargo("Hammer", false);
        Cargo* testCargo5 = new Cargo("Rope", false);

        CargoHandler* testCargoHandler = new HumanHandler(true);
        testCargoHandler->add(new EquipmentHandler(false));

        testCargoHandler->handleCargo(testCargo1);
        testCargoHandler->handleCargo(testCargo2);
        testCargoHandler->handleCargo(testCargo3);
        testCargoHandler->handleCargo(testCargo4);
        testCargoHandler->handleCargo(testCargo5);
    }
}
