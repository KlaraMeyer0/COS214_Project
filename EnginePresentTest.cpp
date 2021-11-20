#include "EnginePresentTest.h"

EnginePresentTest::EnginePresentTest(Launch* la):LaunchTest(la){}
EnginePresentTest::~EnginePresentTest(){}
void EnginePresentTest::output(){
    Rocketship* ship = getShip();
    string res,s;
    char tp = ship->getType();
    int n = ship->;//get number of engines
    bool test = false;
    switch (tp){
    case 'c':
        if (n = 27) test = true;
        break;
    case 'd':
        if (n = 27) test = true;
        break;
    case 's':
        if (n = 9) test = true;
        break;
    default:
        break;
    }
    cout<<"Testing if all engines are attached correctly..."<<endl;
    if (test){
        res = "Passed";
        s = "Proceeding to next test...";
    } else {
        res = "Failed";
        s = "There are "+s+" attached. "+s+" are required.";//get real and expected number as strings
    }
    cout<<"Result: Test "<<res<<endl<<s<<endl;
}
void EnginePresentTest::startLaunch(){
    output();
    l->startLaunch();
}