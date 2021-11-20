#include "StopTest.h"

StopTest::StopTest(Launch* la):LaunchTest(la){flag = false;}
StopTest::~StopTest(){}
void StopTest::output(){
    bool b = true;
    char c;
    do{
        cout<<"The launch is suspended. Input c to continue or a to abort."<<endl;
        cin>>c;
        if (c == 'c'){
            flag = true;
            b = true;
        } if (c == 'a')
            b = true;
        else cout<<"Please input only c or a!"<<endl;
    } while (b);
}
void StopTest::startLaunch(){
    output();
    if (flag)
        l->startLaunch();
    else cout<<"Launch aborted!"<<endl;
}