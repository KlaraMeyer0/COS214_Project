#include "LaunchFile.h"

Rocketship** LaunchFile::getLaunch(){
    return rocketships;
}
LaunchFile::LaunchFile(){
    rocketships = nullptr;
}

void LaunchFile::setLaunch(Rocketship** rocketships,int c){
    if (c < 0) throw std::invalid_argument("Argument outside of range");
    if (rocketships == nullptr) throw std::invalid_argument("Argument is null");
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