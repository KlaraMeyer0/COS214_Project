#include "CargoTest.h"

CargoTest::CargoTest(Launch* la):LaunchTest(la){}
CargoTest::~CargoTest(){}
void CargoTest::output(){

}
void CargoTest::startLaunch(){
    output();
    l->startLaunch();
}