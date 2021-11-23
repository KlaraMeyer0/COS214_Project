#include <limits.h>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../Rocketship.h"
#include "../CrewDragonRocketship.h"
#include "../StarlinkCollection.h"
#include "../Equipment.h"
#include "../Cargo.h"
#include "../CrewDragonSpacecraft.h"
#include "../DragonSpacecraft.h"
#include "../DragonRocketship.h"
#include "../FalconHeavy.h"
#include "../Falcon9.h"
#include <vector>

namespace
{
    string dname = "dragon";
    string cname = "crewdragon";
    string sname = "starlink";
    BaseStation *basestation = new BaseStation();
    SpaceStation *spacestation = new SpaceStation();
    Rocketship *dragon = new DragonRocketship(dname);
    Rocketship *crew = new CrewDragonRocketship(cname);
    Rocketship *starlink = new StarlinkCollection(sname, basestation, spacestation);
    // Tests that the names where set correctly with construction
    TEST(rocketshipTests, NameSetTest)
    {
        // string getName();
        EXPECT_EQ(dragon->getName(), dname);
        EXPECT_EQ(crew->getName(), cname);
        EXPECT_EQ(starlink->getName(), sname);
    }
    // Tests that the types where set correctly during construction
    TEST(rocketshipTests, TypeSetTest)
    {
        // char getType();
        EXPECT_EQ(dragon->getType(), 'd');
        EXPECT_EQ(crew->getType(), 'c');
        EXPECT_EQ(starlink->getType(), 's');
    }
    // Tests that getStation returns the correct station before and after being set
    TEST(rocketshipTests, StationTest)
    {
        EXPECT_EQ(dragon->getStation(), nullptr);
        EXPECT_EQ(crew->getStation(), nullptr);
        EXPECT_EQ(starlink->getStation(), nullptr);

        dragon->attachToStation(basestation);
        crew->attachToStation(basestation);
        starlink->attachToStation(basestation);

        EXPECT_EQ(dragon->getStation(), basestation);
        EXPECT_EQ(crew->getStation(), basestation);
        EXPECT_EQ(starlink->getStation(), basestation);

        dragon->attachToStation(spacestation);
        crew->attachToStation(spacestation);
        starlink->attachToStation(spacestation);

        EXPECT_EQ(dragon->getStation(), spacestation);
        EXPECT_EQ(crew->getStation(), spacestation);
        EXPECT_EQ(starlink->getStation(), spacestation);
    }
    // Tests different cases when loading cargo
    TEST(rocketshipTests, LoadingTest)
    {
        Cargo *rope = new Equipment("rope");
        Cargo *ladder = new Equipment("ladder");
        std::vector<Cargo *> temp;
        temp.push_back(rope);
        temp.push_back(ladder);
        Spacecraft *dSpace = new DragonSpacecraft(50);
        Spacecraft *cSpace = new CrewDragonSpacecraft(75);

        dragon->attachSpacecraft(dSpace);
        crew->attachSpacecraft(cSpace);

        EXPECT_EQ(dragon->testLoading(), false);
        EXPECT_EQ(crew->testLoading(), false);
        EXPECT_EQ(starlink->testLoading(), false);

        dragon->attachCargo(temp);
        crew->attachCargo(temp);

        EXPECT_EQ(dragon->testLoading(), true);
        EXPECT_EQ(crew->testLoading(), true);

        testing::internal::CaptureStdout();
        starlink->attachCargo(temp);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Cannot attach cargo to StarlinkCollection\n");
    }

    // Checks that all engines are able to fire
    TEST(rocketshipTests, testFireTest)
    {
        FalconRocket *f9 = new Falcon9();
        FalconRocket *fHeavy = new FalconHeavy();

        dragon->attachRocket(fHeavy);
        crew->attachRocket(fHeavy);
        starlink->attachRocket(f9);

        EXPECT_EQ(dragon->testFire(), true);
        EXPECT_EQ(crew->testFire(), true);
        EXPECT_EQ(starlink->testFire(), true);
    }
    // Tests to check if the correct number of rockets have been attached
    TEST(rocketshipTests, getRocketTest)
    {
        FalconRocket *f9 = new Falcon9();
        FalconRocket *fHeavy = new FalconHeavy();

        dragon->attachRocket(fHeavy);
        crew->attachRocket(fHeavy);
        starlink->attachRocket(f9);

        EXPECT_EQ(dragon->getRockets(), 27);
        EXPECT_EQ(crew->getRockets(), 27);
        EXPECT_EQ(starlink->getRockets(), 9);
    }
}