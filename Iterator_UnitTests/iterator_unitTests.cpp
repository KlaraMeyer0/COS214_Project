#include <limits.h>
#include <stdexcept>
#include <iostream>

using namespace std;

#include "gtest/gtest.h"
#include "../StarlinkCollection.h"

namespace
{
    // Tests iterator
    TEST(runIteratorTests, iteratingTest)
    {
        cout << "Creating a StarlinkCollection for testing." << endl;

        SpaceStation* testSpaceStation = new SpaceStation();
        BaseStation* testBaseStation = new BaseStation();

        StarlinkCollection* testCollection = new StarlinkCollection("TestCollection", testBaseStation, testSpaceStation);

        StarlinkSatellite* testSatellite1 = new StarlinkSatellite("Test location 1", nullptr);
        StarlinkSatellite* testSatellite2 = new StarlinkSatellite("Test location 2", nullptr);
        StarlinkSatellite* testSatellite3 = new StarlinkSatellite("Test location 3", nullptr);

        testCollection->insert(testSatellite1);
        testCollection->insert(testSatellite2);
        testCollection->insert(testSatellite3);

        testing::internal::CaptureStdout();

        int idx = 0;
        SatelliteIterator* i;
        for (i = testCollection->begin(); !i->equals(testCollection->end()); i->next())
        {
            cout << "Satellite " << idx << " communicates with: " << i->currentSatellite()->getCommunicatesWith() << endl;
            idx++;
        }
        cout << "Satellite " << idx << " communicates with: " << i->currentSatellite()->getCommunicatesWith() << endl;

        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Satellite 0 communicates with: Test location 3\nSatellite 1 communicates with: Test location 2\nSatellite 2 communicates with: Test location 1\n");
    }
}
