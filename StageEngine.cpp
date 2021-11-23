#include "StageEngine.h"

StageEngine::StageEngine() {};

StageEngine::~StageEngine() {};

bool StageEngine::testFire(){
    cout<<"Powering up the engines for a static fire test..."<<endl;
    int r = 1+(rand() % 10);
    if (r == 1){
        cout<<"Some of the engines do not fire!"<<endl;
        return false;
    } else {
        cout<<"All the engines fire at the correct time"<<endl;
        cout<<"Powering down the engines after a successful test."<<endl;
        return true;
    }
}