#include <limits.h>
#include <stdexcept>
#include <iostream>
#include "../BaseStation.h"
#include "../SpaceStation.h"
#include "../LaunchInterface.h"
#include "../Director.h"
#include "../FalconRocket.h"
#include "../Falcon9.h"
#include "gtest/gtest.h"
using namespace std;

namespace
{
    // Testing if the notify() function works correctly ,
    // making sure CommunicationRelayBS ,satStatus is correct
    TEST(StarlinkCollectionTests, notifyTest1)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(1,1);

        SC->getFirstSat()->setStatus(false);
        SC->getCommunicationRelayBS()->notify(SC->getFirstSat());
        map<int,bool> temp =SC->getCommunicationRelayBS()->getStatStatus();

        EXPECT_EQ(temp[SC->getFirstSat()->getName()],0);
    }

    // Testing if the notify() function works correctly
    // making sure BS ,satStatus is correct
    TEST(StarlinkCollectionTests, notifyTest2)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(1,1);

        SC->getFirstSat()->setStatus(false);
        SC->getCommunicationRelayBS()->notify(SC->getFirstSat());
        map<int,bool> temp =SC->getBS()->getSatStatus();

        EXPECT_EQ(temp[SC->getFirstSat()->getName()],0);
    }

    // Testing if the notify() function works correctly ,
    // making sure CommunicationRelayBS ,satStatus is correct
    TEST(StarlinkCollectionTests, notifyTest3)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(1,1);

        SatelliteIterator* it =NULL;
        it =SC->begin();
        it->next();
        it->currentSatellite()->setStatus(false);

        SC->getCommunicationRelaySS()->notify(it->currentSatellite());
        map<int,bool> temp =SC->getCommunicationRelaySS()->getStatStatus();

        EXPECT_EQ(temp[it->currentSatellite()->getName()],0);
    }

    // Testing if the notify() function works correctly
    // making sure SS ,satStatus is correct
    TEST(StarlinkCollectionTests, notifyTest4)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(1,1);

        SatelliteIterator* it =NULL;
        it =SC->begin();
        it->next();
        it->currentSatellite()->setStatus(false);

        SC->getCommunicationRelaySS()->notify(it->currentSatellite());
        map<int,bool> temp =SC->getSS()->getSatStatus();

        EXPECT_EQ(temp[it->currentSatellite()->getName()],0);
    }

    // Testing if the notify() function works correctly ,
    // sending a message form the BaseStation to the StarlinkSatellite
    TEST(StarlinkCollectionTests, notifyTest5)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(1,1);

        SC->getFirstSat()->setStatus(false);
        SC->getCommunicationRelayBS()->notify(SC->getFirstSat());
        base_station->getRelay()->resolve(SC->getFirstSat());

        EXPECT_EQ(SC->getFirstSat()->getStatus(),true);
    }

    // Testing if the notify() function works correctly ,
    // sending a message form the BaseStation to the StarlinkSatellite
    // testing it the CommunicationRelayBS status map correctly updated
    TEST(StarlinkCollectionTests, notifyTest6)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(1,1);

        SC->getFirstSat()->setStatus(false);
        SC->getCommunicationRelayBS()->notify(SC->getFirstSat());
        

        base_station->getRelay()->resolve(SC->getFirstSat());
        map<int,bool> temp =SC->getCommunicationRelayBS()->getStatStatus();

        EXPECT_EQ(temp[SC->getFirstSat()->getName()],1);
    }

    // Testing if the notify() function works correctly ,
    // sending a message form the BaseStation to the StarlinkSatellite
    // testing it the BaseStation status map correctly updated
    TEST(StarlinkCollectionTests, notifyTest7)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(1,1);

        SC->getFirstSat()->setStatus(false);
        SC->getCommunicationRelayBS()->notify(SC->getFirstSat());
        

        base_station->getRelay()->resolve(SC->getFirstSat());
        map<int,bool> temp =SC->getBS()->getSatStatus();

        EXPECT_EQ(temp[SC->getFirstSat()->getName()],1);
    }

    // Testing if the notify() function works correctly ,
    // sending a message form the BaseStation to the StarlinkSatellite
    // testing it the SS status map correctly updated
    TEST(StarlinkCollectionTests, notifyTest8)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(1,1);
        
        SatelliteIterator* it =NULL;
        it =SC->begin();
        it->next();
        it->currentSatellite()->setStatus(false);

        SC->getCommunicationRelaySS()->notify(it->currentSatellite());
        space_station->getRelay()->resolve(it->currentSatellite());
        map<int,bool> temp =SC->getSS()->getSatStatus();

        EXPECT_EQ(temp[it->currentSatellite()->getName()],1);
    }

    // Testing if the notify() function works correctly ,
    // sending a message form the BaseStation to the StarlinkSatellite
    // testing it the CommunicationRelaySS status map correctly updated
    TEST(StarlinkCollectionTests, notifyTest9)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(1,1);

        SatelliteIterator* it =NULL;
        it =SC->begin();
        it->next();
        it->currentSatellite()->setStatus(false);

        SC->getCommunicationRelaySS()->notify(it->currentSatellite());
        space_station->getRelay()->resolve(it->currentSatellite());
        map<int,bool> temp =SC->getCommunicationRelaySS()->getStatStatus();

        EXPECT_EQ(temp[it->currentSatellite()->getName()],1);
    }
}