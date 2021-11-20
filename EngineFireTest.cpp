#include "EngineFireTest.h"

EngineFireTest::EngineFireTest(Launch* la):LaunchTest(la){}
EngineFireTest::~EngineFireTest(){}
void EngineFireTest::output(){

}
void EngineFireTest::startLaunch(){
    output();
    l->startLaunch();
}