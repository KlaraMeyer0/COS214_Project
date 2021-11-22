#include "LaunchReal.h"

LaunchReal::LaunchReal(Rocketship* r, Station *s){
    ship = r;
    space_station = s;
}
LaunchReal::~LaunchReal(){
    ship = nullptr;
    space_station = nullptr;
}
void LaunchReal::startLaunch(){
    ship->Launch(space_station);
}
Rocketship* LaunchReal::getShip(){
    return ship;
}