#include <limits.h>
#include <stdexcept>
#include <gtest/gtest.h>
#include <string>

using namespace std;

#include "../Cargo.h"
#include "../EquipmentHandler.h"
#include "../HumanHandler.h"
#include "../BaseStation.h"
#include "../SpaceStation.h"

namespace
{
    TEST(StationTest, createdTest)
    {
        testing::internal::CaptureStdout();

        SpaceStation* testSpaceStation = new SpaceStation();
        BaseStation* testBaseStation = new BaseStation();

        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Space station Space-RXKJL-68348 has been created.\nBase station Base-KJLXR-28564 has been created.");
    }

    // Tests chain of responsibility
    TEST(ChainOfResponsibilityTest, handlingTest)
    {
        SpaceStation* testSpaceStation = new SpaceStation();
        BaseStation* testBaseStation = new BaseStation();

        Cargo* testCargo1 = new Human("Pete");
        Cargo* testCargo2 = new Equipment("Rope");
        Cargo* testCargo3 = new Human("Kate");
        Cargo* testCargo4 = new Equipment("Hammer");
        Cargo* testCargo5 = new Equipment("Rope");

        CargoHandler* testCargoHandler = new HumanHandler();
        testCargoHandler->add(new EquipmentHandler());

        testing::internal::CaptureStdout();

        testCargoHandler->handleCargo(testCargo1, testSpaceStation);
        testCargoHandler->handleCargo(testCargo2, testBaseStation);
        testCargoHandler->handleCargo(testCargo3, testBaseStation);
        testCargoHandler->handleCargo(testCargo4, testSpaceStation);
        testCargoHandler->handleCargo(testCargo5, testBaseStation);

        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Pete has arrived at Space-RXKJL-68348\nRope has arrived at Base-KJLXR-28564\nKate has arrived at Base-KJLXR-28564\nHammer has arrived at Space-RXKJL-68348\nRope has arrived at Base-KJLXR-28564\n");
    }
}
