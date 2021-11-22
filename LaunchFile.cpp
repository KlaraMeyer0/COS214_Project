#include "LaunchFile.h"

Rocketship** LaunchFile::getLaunch(){
    return rocketships;
}
LaunchFile::LaunchFile(){
    rocketships = nullptr;
}

void LaunchFile::setLaunch(Rocketship** rocketships,int c){
    if (c < 0) throw "Argument outside of range.\n";
    if (rocketships == nullptr) throw "Argument is null.\n";
    this->rocketships = rocketships;
    count = c;
}

LaunchFile::~LaunchFile(){
    for (int i = 0; i < count; i++){
        delete rocketships[i];
    }
    delete rocketships;
}

int LaunchFile::getCount(){
    return count;
}