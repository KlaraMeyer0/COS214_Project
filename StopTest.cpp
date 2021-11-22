#include "StopTest.h"

StopTest::StopTest(Launch* la):LaunchTest(la){flag = false;}
StopTest::~StopTest(){}
void StopTest::output(){
    bool b = true;
    char c;
    do{
        cin.clear();
        cin.ignore(15,'\n');
        cout<<"The launch is suspended. Input c to continue or a to abort."<<endl;
        cin>>c;
        if (c == 'c'){
            flag = true;
            b = false;
        } else if (c == 'a')
            b = false;
        else cout<<"Please input only c or a!"<<endl;
        cin.clear();
        cin.ignore(15, '\n');
    } while (b);
}
void StopTest::startLaunch(){
    output();
    if (flag)
        l->startLaunch();
    else cout<<"Launch aborted!"<<endl;
}