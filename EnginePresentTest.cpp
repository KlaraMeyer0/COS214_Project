#include "EnginePresentTest.h"

EnginePresentTest::EnginePresentTest(Launch* la):LaunchTest(la){}
EnginePresentTest::~EnginePresentTest(){}
void EnginePresentTest::output(){
    Rocketship* ship = getShip();
    string res,s;
    char tp = ship->getType();
    int n = ship->
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

    cout<<"Testing if all engines are attached correctly..."<<endl;
    if (){
        res = "Passed";
        s = "Proceeding to next test...";
    } else {
        res = "Failed";
        s = "There are "+s+" attached.";
    }
    cout<<"Result: Test "<<res<<endl<<s<<endl;
}
void EnginePresentTest::startLaunch(){
    output();
    l->startLaunch();
}