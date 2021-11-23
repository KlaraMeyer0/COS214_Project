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

    // Testing if the getFirstSat() function works correctly
    TEST(StarlinkCollectionTests, headTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(1,1);

        EXPECT_EQ(SC->getFirstSat()->getName(), SC->getSatelliteManager()->getHead()->getName());
    }

    // Testing if the setCommunicationRelayBS() function works correctly
    TEST(StarlinkCollectionTests, setCommunicationRelayBSTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        CommunicationRelay* ptr = new CommunicationRelay(base_station);
        SC->setCommunicationRelayBS(ptr);

        EXPECT_EQ(SC->getCommunicationRelayBS(),(ptr));
    }

    // Testing if the setCommunicationRelaySS() function works correctly
    TEST(StarlinkCollectionTests, setCommunicationRelaySSTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        CommunicationRelay* ptr = new CommunicationRelay(space_station);
        SC->setCommunicationRelaySS(ptr);

        EXPECT_EQ(SC->getCommunicationRelaySS(),(ptr));
    }

    //Testing if the num_B variable in StarlinkCollection is correctly set
    TEST(StarlinkCollectionTests, num_BTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        EXPECT_EQ(SC->getB(),6);
    }

    //Testing if the num_S variable in StarlinkCollection is correctly set
    TEST(StarlinkCollectionTests, num_STest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        EXPECT_EQ(SC->getS(),4);
    }

    //Test if the CommunicationRelayBS is conencted to the correct BaseStation
    TEST(StarlinkCollectionTests, BaseStationTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        EXPECT_EQ(SC->getBS()->getName(),base_station->getName());
    }

    
    //Test if the CommunicationRelaySS is conencted to the correct SpaceStation
    TEST(StarlinkCollectionTests, SpaceStationTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        EXPECT_EQ(SC->getSS()->getName(),space_station->getName());
    }

    //Test if the BaseStation the SatteliteColelction's SattleliteManager is connected to is correct
    TEST(StarlinkCollectionTests, SattleliteManagerBaseStationTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        EXPECT_EQ(SC->getBS()->getName(),SC->getSatelliteManager()->getBaseStation()->getName());
    }

    //Test if the SpaceStation the SatteliteColelction's SattleliteManager is connected to is correct
    TEST(StarlinkCollectionTests, SattleliteManagerSpaceStationTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        EXPECT_EQ(SC->getSS()->getName(),SC->getSatelliteManager()->getSpaceStation()->getName());
    }
    
    //Test if the SpaceStation the SatteliteColelction's CommunicationRelay is connected to is correct
    TEST(StarlinkCollectionTests, CommunicationRelaySpaceStationTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        
        EXPECT_EQ(SC->getSS()->getName(),SC->getCommunicationRelaySS()->getRelayTo()->getName());
    }

    //Test if the BaseStation the SatteliteColelction's CommunicationRelay is connected to is correct
    TEST(StarlinkCollectionTests, CommunicationRelayBaseStationTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        
        EXPECT_EQ(SC->getBS()->getName(),SC->getCommunicationRelayBS()->getRelayTo()->getName());
    }

    //Test if the clone function copies the satStatus maps accross the CommunicationRelayBS relays
    TEST(StarlinkCollectionTests, cloneRelayBSMapsTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        StarlinkCollection* SCclone = SC->clone();

        EXPECT_EQ(SC->getCommunicationRelayBS()->getStatStatus() ,SCclone->getCommunicationRelayBS()->getStatStatus());
    }


    //Test if the clone function copies the satStatus maps accross the CommunicationRelaySS relays
    TEST(StarlinkCollectionTests, cloneRelaySSMapsTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        StarlinkCollection* SCclone = SC->clone();

        EXPECT_EQ(SC->getCommunicationRelaySS()->getStatStatus() ,SCclone->getCommunicationRelaySS()->getStatStatus());
    }


    //Test if the maps are consistent accross the CommunicationRelayBS and BaseStation
    TEST(StarlinkCollectionTests, RelayBSBaseStationMapsTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        StarlinkCollection* SCclone = SC->clone();

        EXPECT_EQ(SC->getBS()->getSatStatus() ,SC->getCommunicationRelayBS()->getStatStatus());
    }

    //Test if the maps are consistent accross the CommunicationRelaySS and SpaceStation
    TEST(StarlinkCollectionTests, RelaySSSpaceStationMapsTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        StarlinkCollection* SCclone = SC->clone();

        EXPECT_EQ(SC->getSS()->getSatStatus() ,SC->getCommunicationRelaySS()->getStatStatus());
    }

    //Test if the Clone() function creates a viable clone
    TEST(StarlinkCollectionTests, cloneTest)
    {
        BaseStation *base_station = new BaseStation();
        SpaceStation *space_station = new SpaceStation();

        StarlinkCollection* SC = new StarlinkCollection("Test StarlinkCollection",base_station,space_station);

        FalconRocket* rObj =new Falcon9();
        SC->attachRocket(rObj);

        SC->setSatellites(6,4);

        StarlinkCollection* SCclone = SC->clone();

        //function definition in StarlinkCollection.cpp
        bool b =true;
        if(!SC->isViableClone(SCclone))
            b =false;

        EXPECT_EQ(b,true);
    }

}