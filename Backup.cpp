#include "Backup.h"

Backup::Backup(LaunchInterface* i){
    interface = i;
}

Backup::~Backup(){}

void Backup::execute(){
    interface->storeFile();
}
void Backup::undo(){
    interface->restoreFile();
}