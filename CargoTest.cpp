#include "CargoTest.h"

CargoTest::CargoTest(Launch* la):LaunchTest(la){}
CargoTest::~CargoTest(){}
void CargoTest::output(){
    Rocketship* ship = getShip();
    string res,s;
    bool test = false;
    cout<<"Testing if cargo is loaded..."<<endl;
    test = ship->testLoading();//Code to check if cargo present
    if (test){
        res = "Passed";
        s = "Proceeding to next test...";
    } else {
        res = "Failed";
        s = "There is no cargo attached.";
        Cancel();
    }
    cout<<"Result: Test "<<res<<endl<<s<<endl;
}
void CargoTest::startLaunch(){
    output();
    l->startLaunch();
}