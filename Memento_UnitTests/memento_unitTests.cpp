#include <limits.h>
#include <stdexcept>
#include "../LaunchInterface.h"
#include "../DragonRocketship.h"
#include "../SpaceStation.h"
#include "../BaseStation.h"
#include "../FalconHeavy.h"
#include <gtest/gtest.h>

namespace
{
    // Test Launch Interface functions
    // LaunchInterface tests:
    // Checks if the rocketships were added by the addrocket correctly
    TEST(InterfaceTest, AddRocketTest)
    {
        Station* s = new SpaceStation();
        Station* b = new BaseStation();
        LaunchInterface* l = new LaunchInterface(s,b);
        Rocketship** r = new Rocketship*[3];
        for (int i = 0; i < 3; i++){
            r[i] = new DragonRocketship("foo");
            l->addRocketship(r[i]);
        }
        EXPECT_EQ(l->getAllRockets()[1], r[1]);
    }
    // Checks if the correct setup was backed up into a LauncFile
    TEST(InterfaceTest, RetrieveLaunchTest)
    {
        Station* s = new SpaceStation();
        Station* b = new BaseStation();
        LaunchInterface* l = new LaunchInterface(s,b);
        Rocketship** r = new Rocketship*[3];
        for (int i = 0; i < 3; i++){
            r[i] = new DragonRocketship("foo");
            r[i]->attachSpacecraft(new DragonSpacecraft(0));
            r[i]->attachRocket(new FalconHeavy());
            vector<Cargo*> a;
            r[i]->attachCargo(a);
            l->addRocketship(r[i]);
        }
        EXPECT_EQ(l->retrieveLaunchFile()->getLaunch()[1]->getName(),r[1]->getName());
    }

    //LaunchFile tests:
    // Checks if the setLaunch works correctly, Valid argument
    TEST(FileTest, setLaunchTest)
    {
        LaunchFile* f = new LaunchFile();
        Rocketship** r = new Rocketship*[1];
        r[0] = new DragonRocketship("test");
        f->setLaunch(r,1);
        EXPECT_EQ(f->getLaunch(),r);
    }
    // Checks if the setLaunch works correctly, Invalid argument 1
    TEST(FileTest, setLaunchTest1)
    {
        LaunchFile* f = new LaunchFile();
        Rocketship** r = new Rocketship*[1];
        r[0] = new DragonRocketship("test");
        try {
            f->setLaunch(r,-1);
            FAIL();
        } catch(std::invalid_argument & err) {
            EXPECT_EQ(err.what(),std::string("Argument outside of range"));
        } catch(...) {
            FAIL();
        } 
    }
    // Checks if the setLaunch works correctly, Invalid argument 2
    TEST(FileTest, setLaunchTest2)
    {
        LaunchFile* f = new LaunchFile();
        try {
            f->setLaunch(nullptr,1);
            FAIL();
        } catch(std::invalid_argument & err) {
            EXPECT_EQ(err.what(),std::string("Argument is null"));
        } catch(...) {
            FAIL();
        }
    }
    //LaunchCaretaker tests:
    // Checks if the launchfile is set correctly, Valid argument
    TEST(CaretakerTest, setTest)
    {   
        LaunchFile* f = new LaunchFile();
        Rocketship** r = new Rocketship*[1];
        r[0] = new DragonRocketship("test");
        f->setLaunch(r,1);
        LaunchCaretaker* c = new LaunchCaretaker();
        c->setFile(f);
        EXPECT_EQ(c->contains(f),true);
    }
    // Checks if the launchfile is set correctly, Invalid argument
    TEST(CaretakerTest, setTest1)
    {
        LaunchCaretaker* c = new LaunchCaretaker();
        try {
            c->setFile(nullptr);
            FAIL();
        } catch(std::invalid_argument & err) {
            EXPECT_EQ(err.what(),std::string("Argument is null"));
        } catch(...) {
            FAIL();
        }
    }
    // Checks if the launchfile is contained, Valid argument
    TEST(CaretakerTest, containsTest)
    {
        LaunchFile* f = new LaunchFile();
        Rocketship** r = new Rocketship*[1];
        r[0] = new DragonRocketship("test");
        f->setLaunch(r,1);
        LaunchCaretaker* c = new LaunchCaretaker();
        c->setFile(f);
        EXPECT_EQ(c->contains(f),true);
    }
    // Checks if the launchfile is contained, Invalid argument
    TEST(CaretakerTest, containsTest1)
    {
        LaunchFile* f = new LaunchFile();
        LaunchFile* l = new LaunchFile();
        LaunchCaretaker* c = new LaunchCaretaker();
        c->setFile(f);
        EXPECT_EQ(c->contains(l),false);
    }
    // Checks if the file gets returned correctly, Valid argument
    TEST(CaretakerTest, getTest)
    {
        LaunchCaretaker* c = new LaunchCaretaker();
        LaunchFile* f = new LaunchFile();
        c->setFile(f);
        EXPECT_EQ(c->getFile(0),f);
    }
    // Checks if the file gets returned correctly, Invalid argument
    TEST(CaretakerTest, getTest1)
    {
        LaunchCaretaker* c = new LaunchCaretaker();
        LaunchFile* f = new LaunchFile();
        c->setFile(f);
        try {
            c->getFile(2);
            FAIL();
        } catch(std::invalid_argument & err) {
            EXPECT_EQ(err.what(),std::string("Argument outside of range"));
        } catch(...) {
            FAIL();
        }
    }
    // Checks if the file gets removed correctly, Valid argument
    TEST(CaretakerTest, removeTest)
    {
        LaunchCaretaker* c = new LaunchCaretaker();
        LaunchFile* f = new LaunchFile();
        Rocketship** r = new Rocketship*[1];
        r[0] = new DragonRocketship("test");
        f->setLaunch(r,1);
        c->setFile(f);
        c->removeFile(0);
        EXPECT_EQ(c->contains(f),false);
    }
    // Checks if the file gets removed correctly, Invalid argument
    TEST(CaretakerTest, removeTest1)
    {
        LaunchCaretaker* c = new LaunchCaretaker();
        LaunchFile* f = new LaunchFile();
        c->setFile(f);
        try {
            c->removeFile(1);
            FAIL();
        } catch(std::invalid_argument & err) {
            EXPECT_EQ(err.what(),std::string("Argument outside of range"));
        } catch(...) {
            FAIL();
        }
    }
    // Checks if the correct file size is returned
    TEST(CaretakerTest, getSizeTest)
    {
        LaunchCaretaker* c = new LaunchCaretaker();
        LaunchFile* f = new LaunchFile();
        c->setFile(f);
        EXPECT_EQ(c->getSize(),1);
    }
}