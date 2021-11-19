#include "LaunchInterface.h"

void LaunchInterface::setLaunchFile(LaunchFile* file){
    rocketships = file->getLaunch();
}
LaunchFile* LaunchInterface::retieveLaunchFile(){
    LaunchFile* f = new LaunchFile();
    //make deepcopy of rocket array
    f->setLaunch();//put deepcopy here
    return f;
}