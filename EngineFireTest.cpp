#include "EngineFireTest.h"

EngineFireTest::EngineFireTest(Launch* la):LaunchTest(la){}
EngineFireTest::~EngineFireTest(){}
void EngineFireTest::output(){
    Rocketship* ship = getShip();
    string res,s;
    bool test = false;
    cout<<"Testing if all engines fire correctly..."<<endl;
    test = ship->testFire();//code to start engine fire and check if all fire
    if (test){
        res = "Passed";
        s = "Proceeding to next test...";
    } else {
        res = "Failed";
        s = "The engines are not firing correctly";
        Cancel();
    }
    cout<<"Result: Test "<<res<<endl<<s<<endl;
}
void EngineFireTest::startLaunch(){
    output();
    l->startLaunch();
}