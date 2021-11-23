#include <limits.h>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../CrewDragonBay.h"
#include "../DragonBay.h"
#include "../StarlinkBay.h"
#include "../RocketshipEngineer.h"

namespace
{

    RocketshipBay *crewBay = new CrewDragonBay();
    RocketshipBay *dragonBay = new DragonBay();
    RocketshipBay *starlinkBay = new StarlinkBay();
    BaseStation *base = new BaseStation();
    SpaceStation *space = new SpaceStation();

    // Tests that functions called in Engineer
    // Tests the initial creation function
    TEST(BuilderTests, setNameSuccessTest)
    {
        starlinkBay->setName("star", base, space);
        testing::internal::CaptureStdout();
        crewBay->setName("crewRocket", base);
        dragonBay->setName("dragonRocket", base);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "crewRocket has attached to station Base-KJLXR-28564\ndragonRocket has attached to station Base-KJLXR-28564\n");
    }
    // Tests that the build body successfully builds the spacecraft
    TEST(BuilderTests, buildBodyTest)
    {
        testing::internal::CaptureStdout();
        crewBay->buildBody();
        dragonBay->buildBody();
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "CrewDragon spacecraft successfully created\nDragon spacecraft successfully created\n");
    }
    // Tests that the rockets are successfully made
    TEST(BuilderTests, buildRocketTest)
    {
        testing::internal::CaptureStdout();
        crewBay->buildRocket();
        dragonBay->buildRocket();
        starlinkBay->buildRocket();
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Successfully created FalconHeavy rocket\nSuccessfully created FalconHeavy rocket\nSuccessfully created Falcon9 rocket\n");
    }
}