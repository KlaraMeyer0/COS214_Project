#include "EnginePresentTest.h"

EnginePresentTest::EnginePresentTest(Launch* la):LaunchTest(la){}
EnginePresentTest::~EnginePresentTest(){}
void EnginePresentTest::output(){
    Rocketship* ship = getShip();
    string res,s;
    char tp = ship->getType();
    int i = 27,n = ship->getRockets();//get number of engines
    bool test = false;
    switch (tp){
    case 'c':
        if (n == 27) test = true;
        break;
    case 'd':
        if (n == 27) test = true;
        break;
    case 's':
        if (n == 9) {
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
void EnginePresentTest::startLaunch(){
    output();
    l->startLaunch();
}