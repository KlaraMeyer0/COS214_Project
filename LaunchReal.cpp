#include "LaunchReal.h"

LaunchReal::LaunchReal(Rocketship* r, Station *s){
    ship = r;
    space_station = s;
    goAhead = true;
}
LaunchReal::~LaunchReal(){
    ship = nullptr;
    space_station = nullptr;
}
void LaunchReal::startLaunch(){
    if (goAhead){
        ship->Launch(space_station);        
    } else{
        cout<<"Tests failed, launch aborted..."<<endl;
    }
}
Rocketship* LaunchReal::getShip(){
    return ship;
}
void LaunchReal::Cancel(){
    goAhead = false;
}