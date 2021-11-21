#include <limits.h>
#include <stdexcept>
#include <iostream>

using namespace std;

//#include "gtest/gtest.h"
#include "StarlinkCollection.h"

namespace
{
    // Tests chain of responsibility
    void runIteratorTests() {
        cout << "Creating a StarlinkCollection for testing." << endl;
        StarlinkCollection* testCollection = new StarlinkCollection("TestCollection", nullptr, nullptr);
        StarlinkSatellite* testSatellite1 = new StarlinkSatellite("Test location 1", nullptr);
        StarlinkSatellite* testSatellite2 = new StarlinkSatellite("Test location 1", nullptr);
        StarlinkSatellite* testSatellite3 = new StarlinkSatellite("Test location 1", nullptr);

        testCollection->insert(testSatellite1);
        testCollection->insert(testSatellite2);
        testCollection->insert(testSatellite2);

        int idx = 0;
        SatelliteIterator* i;
        for (i = testCollection->begin(); !(testCollection->end()); ++i)
        {
            cout << "Satellite " << idx << " communicates with: " << i->currentSatellite()->getCommunicatesWith() << endl;
            idx++;
        }
    }
}
