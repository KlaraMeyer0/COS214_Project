#include <limits.h>
#include <stdexcept>
#include "../Spacecraft.h"
#include "../SpacecraftFactory.h"
#include "../CrewDragonFactory.h"
#include "../DragonFactory.h"
#include "../DragonSpacecraft.h"
#include "../CrewDragonSpacecraft.h"
#include <gtest/gtest.h>

namespace
{
    // Test CargoFactory Hierarchy
    TEST(EquipmentFactory)
    {

    }
    TEST()
    {

    }

    // // Test RocketFactory Hierarchy
    // TEST()
    // {

    // }
    // TEST()
    // {

    // }

    // Test SpacecraftFactory Hierarchy
    //Tests for Dragon:
    //Test if the object is created by looking at the output
    TEST(DragonFactoryTest, CreationTest)
    {
        SpacecraftFactory *factory = new DragonFactory();
        testing::internal::CaptureStdout();
        factory->startFactory();
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Dragon spacecraft successfully create\n");
    }
    TEST(DragonFactoryTest, CapacityTest)
    {
        SpacecraftFactory *factory = new DragonFactory();
        EXPECT_EQ((factory->startFactory())->getCapacity(), 50);
    }
    //Tests for CrewDragon:
    //Test if the object is created by looking at the output
    TEST(CrewDragonFactoryTest, CreationTest)
    {
        SpacecraftFactory *factory = new CrewDragonFactory();
        testing::internal::CaptureStdout();
        factory->startFactory();
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "CrewDragon spacecraft successfully create\n");
    }
    //Test if the spacecraft has been created with the correct capacity
    TEST(CrewDragonFactoryTest, CapacityTest)
    {
        SpacecraftFactory *factory = new CrewDragonFactory();
        EXPECT_EQ(factory->startFactory()->getCapacity(), 75);
    }
}