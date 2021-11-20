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
        if (n = 27) test = true;
        break;
    case 'd':
        if (n = 27) test = true;
        break;
    case 's':
        if (n = 9) {
            test = true;
            i = 9;
            }
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
        stringstream ss;
        string aa,aaa;
        ss<<n;
        ss>>aa;
        ss.clear();
        ss<<i;
        ss>>aaa;
        s = "There are "+aaa+" attached. "+aa+" are required.";//get real and expected number as strings
    }
    cout<<"Result: Test "<<res<<endl<<s<<endl;
}
void EngineFireTest::startLaunch(){
    output();
    l->startLaunch();
}