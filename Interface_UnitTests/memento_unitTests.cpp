#include <limits.h>
#include <stdexcept>
#include "../SpaceStation.h"
#include "../LaunchInterface.h"
#include "../DragonRocketship.h"
#include <gtest/gtest.h>

namespace
{
    // Test Launch Interface functions
    // LaunchInterface tests:
    // Checks if the rocketships were added by the addrocket correctly
    TEST(InterfaceTest, AddRocketTest)
    {
        Station* s = new SpaceStation();
        LaunchInterface* l = new LaunchInterface(s);
        Rocketship** r = new Rocketship*[3];
        for (int i = 0; i < 3; i++){
            r[i] = new DragonRocketship("foo");
            l->addRocketship(r[i]);
        }
        EXPECT_EQ(l->getAllRockets(), r);
    }
    // Checks if the correct setup was backed up into a LauncFile
    TEST(InterfaceTest, RetrieveLaunchTest)
    {
        Station* s = new SpaceStation();
        LaunchInterface* l = new LaunchInterface(s);
        Rocketship** r = new Rocketship*[3];
        for (int i = 0; i < 3; i++){
            r[i] = new DragonRocketship("foo");
            l->addRocketship(r[i]);
        }
        EXPECT_EQ(l->retrieveLaunchFile()->getLaunch(),r);
    }

    //LaunchCaretaker tests:
    // Checks if the launchfile was stored correctly, Valid argument
    TEST(CaretakerTest, getFileTest)
    {
        LaunchFile* f = new LaunchFile();
        LaunchCaretaker* c = new LaunchCaretaker();
        c->setFile(f);
        EXPECT_EQ(c->contains(f),true);
    }
    // Checks if the launchfile was stored correctly, Invalid argument
    TEST(CaretakerTest, getFileTest1)
    {
        LaunchFile* f = new LaunchFile();
        LaunchFile* l = new LaunchFile();
        LaunchCaretaker* c = new LaunchCaretaker();
        c->setFile(f);
        EXPECT_EQ(c->contains(l),false);
    }

    // Checks if the file gets removed correctly
    TEST(CaretakerTest, removeTest)
    {
        LaunchCaretaker* c = new LaunchCaretaker();
        LaunchFile* f1 = new LaunchFile();
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
}