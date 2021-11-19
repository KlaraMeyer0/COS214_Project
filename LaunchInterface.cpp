#include "LaunchInterface.h"

void LaunchInterface::setLaunchFile(LaunchFile* file){//sets the given Launchfile as the current rocket setup
    rocketCount = file->getCount();
    rocketships = file->getLaunch();
}
LaunchFile* LaunchInterface::retieveLaunchFile(){//create backup Launchfile for current selection of rockets
    LaunchFile* f = new LaunchFile();
    //make deepcopy of current rocket array
    Rocketship** r = new Rocketship*[rocketCount];
    for (int i = 0; i < rocketCount; i++)
        r[i] = rocketships[i]->clone();
    f->setLaunch(r,rocketCount);//put deepcopy here
    return f;
}