#include "EnginePresentTest.h"

EnginePresentTest::EnginePresentTest(Launch* la):LaunchTest(la){}
EnginePresentTest::~EnginePresentTest(){}
void EnginePresentTest::output(){
    string res,s;
    cout<<"Testing if all engines are attached correctly..."<<endl;
    if (/* condition */){
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