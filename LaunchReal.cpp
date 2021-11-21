#include "LaunchReal.h"

LaunchReal::LaunchReal(Rocketship* r){
    ship = r;
    t = true;
}
LaunchReal::~LaunchReal(){
    ship = nullptr;
}
void LaunchReal::startLaunch(){
    ship->Launch();
}
Rocketship* LaunchReal::getShip(){
    return ship;
}