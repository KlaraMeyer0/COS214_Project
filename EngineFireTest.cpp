#include "EngineFireTest.h"

EngineFireTest::EngineFireTest(Launch* la):LaunchTest(la){}
EngineFireTest::~EngineFireTest(){}
void EngineFireTest::output(){
    Rocketship* ship = getShip();
    string res,s;
    char tp = ship->getType();
    bool test = false;
    switch (tp){
    case 'c':
        
        break;
    case 'd':
        
        break;
    case 's':
        
        break;
    default:
        break;
    }
    cout<<"Testing if all engines fire correctly..."<<endl;
    //code to start engine fire and check if all fire
    if (test){
        res = "Passed";
        s = "Proceeding to next test...";
    } else {
        res = "Failed";
        s = "The engines are not firing correctly";
    }
    cout<<"Result: Test "<<res<<endl<<s<<endl;
}
void EngineFireTest::startLaunch(){
    output();
    l->startLaunch();
}