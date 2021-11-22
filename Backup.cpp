#include "Backup.h"

Backup::Backup(LaunchInterface* i) : Work(i){}

Backup::~Backup(){}

void Backup::execute(){
    launch_interface->storeFile();
}
void Backup::undo(){
    launch_interface->restoreFile();
}