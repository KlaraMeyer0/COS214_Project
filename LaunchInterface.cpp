#include "LaunchInterface.h"

void LaunchInterface::setLaunchFile(LaunchFile* file){//sets the given Launchfile as the current rocket setup
    rocketCount = file->getCount();
    rocketships = file->getLaunch();
}
LaunchFile* LaunchInterface::retrieveLaunchFile(){//create backup Launchfile for current selection of rockets
    LaunchFile* f = new LaunchFile();
    //make deepcopy of current rocket array
    Rocketship** r = new Rocketship*[rocketCount];
    for (int i = 0; i < rocketCount; i++)
        r[i] = rocketships[i]->clone();
    f->setLaunch(r,rocketCount);
    return f;
}
LaunchInterface::LaunchInterface(){
    launchCaretaker = new LaunchCaretaker();
}
LaunchInterface::~LaunchInterface(){
    delete launchCaretaker;
    for (int i = 0; i < rocketCount; i++)
        delete rocketships[i];
    delete rocketships;
}
void LaunchInterface::TestLaunch(){

}
void LaunchInterface::addRocketship(Rocketship* r){
    rocketCount++;
    Rocketship** rs = new Rocketship*[rocketCount];
    rs[rocketCount-1] = r;
}
void LaunchInterface::storeFile(LaunchFile* f){
    if (!launchCaretaker->contains(f)){
        launchCaretaker->setFile(f);
    }
}
void LaunchInterface::getFile(){
    
}