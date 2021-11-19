#include <limits.h>
#include <stdexcept>
#include <gtest/gtest.h>
#include "Falcon9.h"
#include "FalconHeavy.h"

namespace
{
    // Tests state
    void runStateTests() {
        Falcon9 F9 = Falcon9();
        cout << "Testing falcon 9" << endl;
        F9.turnOn();
        F9.turnOn();
        F9.turnOff();
        Falcon9 F92 = F9.clone();
        cout << "Testing falcon 9 clone" << endl;
        F92.turnOn();
        F92.turnOff();
        F92.turnOn();
        F92.turnOff();
        cout << "" << endl;
        FalconHeavy FH = FalconHeavy();
        cout << "Testing falcon heavy" << endl;
        FH.turnOn();
        FH.turnOn();
        FH.turnOff();
        FalconHeavy FH2 = FH2.clone();
        cout << "Testing falcon heavy clone" << endl;
        FH2.turnOn();
        FH2.turnOff();
        FH2.turnOn();
        FH2.turnOff();
    }
}