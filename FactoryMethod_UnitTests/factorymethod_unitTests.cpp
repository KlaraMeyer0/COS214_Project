#include <limits.h>
#include <stdexcept>
#include "../SpacecraftFactory.h"
#include "../CrewDragonFactory.h"
#include "../DragonFactory.h"
#include "../DragonSpacecraft.h"
#include "../CrewDragonSpacecraft.h"
#include "../HumanFactory.h"
#include "../EquipmentFactory.h"
#include "../Human.h"
#include "../Equipment.h"
#include "../Falcon9Factory.h"
#include "../FalconHeavyFactory.h"
#include <gtest/gtest.h>

namespace
{
    // Test CargoFactory Hierarchy
    // EquipmentFactory tests:
    // Checks if equipment is constructed with correct name
    TEST(EquipmentFactoryTest, correctConstructionTest)
    {
        CargoFactory *factory = new EquipmentFactory();
        std::string name = "rope";
        EXPECT_EQ(factory->startFactory(name)->getName(), name);
    }
    // Checks that equipment is made as equipment and not as human
    TEST(EquipmentFactoryTest, isEuipmentTest)
    {
        CargoFactory *factory = new EquipmentFactory();
        std::string name = "rope";
        EXPECT_EQ(factory->startFactory(name)->isHuman(), false);
    }

    // HumanFactory tests:
    // Checks if human is made with correct name
    TEST(HumanFactoryTest, correctConstructionTest)
    {
        CargoFactory *factory = new HumanFactory();
        std::string name = "Roberto";
        EXPECT_EQ(factory->startFactory(name)->getName(), name);
    }
    // Checks if human is created as human and not equipment
    TEST(HumanFactoryTest, isHumanTest)
    {
        CargoFactory *factory = new HumanFactory();
        std::string name = "Roberto";
        EXPECT_EQ(factory->startFactory(name)->isHuman(), true);
    }

    // Test RocketFactory Hierarchy
    // Checks if new falcon9 is created
    TEST(Falcon9FactoryTests, createdTest)
    {
        RocketFactory *factory = new Falcon9Factory();
        testing::internal::CaptureStdout();
        factory->startFactory();
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Successfully created Falcon9 rocket\n");
    }
    // Checks if new falconheavy is created
    TEST(FalconHeavyFactoryTests, createdTest)
    {
        RocketFactory *factory = new FalconHeavyFactory();
        testing::internal::CaptureStdout();
        factory->startFactory();
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Successfully created FalconHeavy rocket\n");
    }

    // Test SpacecraftFactory Hierarchy
    // Tests for Dragon:
    // Test if the object is created by looking at the output
    TEST(DragonFactoryTest, CreationTest)
    {
        SpacecraftFactory *factory = new DragonFactory();
        testing::internal::CaptureStdout();
        factory->startFactory();
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Dragon spacecraft successfully created\n");
    }
    TEST(DragonFactoryTest, CapacityTest)
    {
        SpacecraftFactory *factory = new DragonFactory();
        EXPECT_EQ((factory->startFactory())->getCapacity(), 50);
    }
    // Tests for CrewDragon:
    // Test if the object is created by looking at the output
    TEST(CrewDragonFactoryTest, CreationTest)
    {
        SpacecraftFactory *factory = new CrewDragonFactory();
        testing::internal::CaptureStdout();
        factory->startFactory();
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "CrewDragon spacecraft successfully created\n");
    }
    // Test if the spacecraft has been created with the correct capacity
    TEST(CrewDragonFactoryTest, CapacityTest)
    {
        SpacecraftFactory *factory = new CrewDragonFactory();
        EXPECT_EQ(factory->startFactory()->getCapacity(), 75);
    }
}