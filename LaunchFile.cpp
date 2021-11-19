#include "LaunchFile.h"

Rocketship** LaunchFile::getLaunch(){
    return rocketships;
}
LaunchFile::LaunchFile(){}
void LaunchFile::setLaunch(Rocketship** rocketships,int c){
    this->rocketships = rocketships;
    count = c;
}
LaunchFile::~LaunchFile(){
    for (int i = 0; i < count; i++){
        delete rocketships[i];
    }
    delete rocketships;
}
void LaunchFile::setLaunch(Rocketship** rocketships, int c){
    count = c;
    this->rocketships = rocketships;
}
int LaunchFile::getCount(){
    return count;
}